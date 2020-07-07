package httpclient

import (
	"io"
	"io/ioutil"
	"net/http"
	"net/url"
	"os"
	"sync"
	"time"

	"refresh_agent/utils"
)

var client *http.Client
var buffPool sync.Pool

func init() {
	client = &http.Client{}
	http.DefaultTransport.(*http.Transport).MaxIdleConnsPerHost = 2000
	http.DefaultTransport.(*http.Transport).MaxIdleConns = 20000
}

type HttpClient struct{}

func NewHttpClient() *HttpClient {
	httpClient := HttpClient{}
	return &httpClient
}

func (this *HttpClient) replaceUrl(srcUrl string, ip string) string {
	httpPrefix := "http://"
	parsedUrl, err := url.Parse(srcUrl)
	if err != nil {
		return ""
	}
	return httpPrefix + ip + parsedUrl.Path
}

func (this *HttpClient) downLoadFile(resp *http.Response) error {
	out, err := os.OpenFile("/dev/null", os.O_RDWR|os.O_CREATE|os.O_APPEND, 0666)
	defer out.Close()
	_, err = io.Copy(out, resp.Body)
	return err
}

func (this *HttpClient) Fetch(dstUrl string, method string, proxyHost string, header map[string]string, preload bool, timeout int64) (*http.Response, error) {
	// proxyHost 换掉 url 中请求
	newUrl := this.replaceUrl(dstUrl, proxyHost)
	req, _ := http.NewRequest(method, newUrl, nil)
	for k, v := range header {
		req.Header.Add(k, v)
	}
	req.Host = utils.GetUrlHost(dstUrl)
	client.Timeout = time.Duration(timeout) * time.Second
	resp, err := client.Do(req)
	if resp == nil || err != nil {
		return resp, err
	}

	if preload {
		err := this.downLoadFile(resp)
		if err != nil {
			return nil, err
		}
	}

	io.Copy(ioutil.Discard, resp.Body)
	resp.Body.Close()

	return resp, nil
}
