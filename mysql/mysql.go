package mysql

import (
	"fmt"
	"github.com/jmoiron/sqlx"
	"time"
)

// Config info
type Config struct {
	Host        string
	Port        int
	User        string
	Pass        string
	Database    string
	Charset     string
	Active      int           //SetMaxOpenConns,recommendation 100
	Idle        int           //SetMaxIdleConns,recommendation 2
	IdleTimeout time.Duration //SetConnMaxLifetime,recommendation 5 second
}

// New a sqlx.DB.
func NewMysqlSqlDB(c *Config) (*sqlx.DB, error) {
	if c.Charset == "" {
		c.Charset = "utf-8"
	}
	DSN := fmt.Sprint(c.User, ":", c.Pass, "@tcp(", c.Host, ":", c.Port, ")/", c.Database, "?charset=", c.Charset)
	driverName := "mysql"
	db, err := sqlx.Connect(driverName, DSN)
	if err != nil {
		return db, err
	}
	if c.Active != 0 {
		db.SetMaxOpenConns(c.Active) //设置连接池最大打开数据库连接数，<=0表示不限制打开连接数，默认为0

	}
	if c.Idle != 0 {
		db.SetMaxIdleConns(c.Idle) //<=0表示不保留空闲连接，默认值2
	}

	if c.IdleTimeout != 0 {
		db.SetConnMaxLifetime(c.IdleTimeout) //设置连接超时时间
	}
	return db, err
}
