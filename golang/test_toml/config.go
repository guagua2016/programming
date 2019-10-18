package main

import (
	"fmt"
	"path/filepath"
	"sync"
	"time"

	"github.com/BurntSushi/toml"
)

//https://github.com/BurntSushi/toml.git

type tomlConfig struct {
	Title   string
	Owner   ownerInfo
	DB      database `toml:"database"`
	Servers map[string]server
	Clients clients
}

type ownerInfo struct {
	Name string
	Org  string `toml:"organization"`
	Bio  string
	DOB  time.Time
}

type database struct {
	Server  string
	Ports   []int
	ConnMax int `toml:"connection_max"`
	Enabled bool
}

type server struct {
	IP string
	DC string
}

type clients struct {
	Data  [][]interface{}
	Hosts []string
}

var (
	cfg  *tomlConfig
	once sync.Once
)

func Config() *tomlConfig {
	once.Do(func() {
		filePath, err := filepath.Abs("config.toml")
		if err != nil {
			panic(err)
		}
		fmt.Printf("parse toml file once. filePath: %s\n", filePath)
		if _, err := toml.DecodeFile(filePath, &cfg); err != nil {
			panic(err)
		}
	})
	return cfg
}
