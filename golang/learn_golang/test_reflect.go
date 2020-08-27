package main

import (
	"crypto/md5"
	"encoding/hex"
	"fmt"
)

//生成32位md5字串
func Md5(s string) string {
	h := md5.New()
	h.Write([]byte(s))
	return hex.EncodeToString(h.Sum(nil))
}

func main() {
	ret := Md5(`{"payAmount":100,"adId":101097648,"appType":1,"clientIp":"127.0.0.1","dataType":1,"ascribeType":1,"channel":1,"imei":"XJMyaLt8fDlv4a9b8/0RNQ==","type":1,"pkg":"com.oppo.test","mac":"TEViR6jSgD/lECBl3Ah70eNy2gUQrQlekHkWqEGkZsU=","timestamp":1571995483916}1571995483916e0u6fnlag06lc3pl`)
	fmt.Println(ret)
}
