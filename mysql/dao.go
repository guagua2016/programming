package mysql

import (
	"fmt"
	"github.com/jmoiron/sqlx"
)

type Dao struct {
	db *sqlx.DB
}

//New a Dao.
func NewDao(db *sqlx.DB) *Dao {
	d := &Dao{
		db: db,
	}
	return d
}

func (self *Dao) QueryXX() {
	sql := "SELECT * FROM users WHERE id=?"
	var (
		id     int
		name   string
		salary int
	)
	if err := self.db.QueryRowx(sql, id).Scan(&id, &name, &salary); err != nil {
		fmt.Println(err)
		return
	} else {
		fmt.Println(id, name, salary)
	}
	/*
	   type Employee struct {
	       id     int
	       name   string
	       salary int
	   }
	   employeeInfo := &Employee{}
	   if err := self.db.QueryRowx(sql, id).StructScan(employeeInfo); err != nil {
	       fmt.Println(err)
	       return
	   } else {
	       fmt.Println(employeeInfo)
	   }
	*/
}

//query
func (self *Dao) QueryXXXX() {
	sql := "SELECT * FROM users WHERE id < ?"
	rows, err := self.db.Queryx(sql, 10)
	if err != nil {
		fmt.Println(err)
		return
	}
	defer rows.Close()

	for rows.Next() {
		var (
			id     int
			name   string
			salary int
		)
		err = rows.Scan(&id, &name, &salary)
		if err != nil {
			fmt.Println(err)
		}
	}
	/*
	   // rows.StructScan
	   type Employee struct {
	       id     int
	       name   string
	       salary int
	   }
	   employeeInfo := &Employee{}
	   for rows.Next() {
	       err = rows.StructScan(employeeInfo)
	       if err != nil {
	           fmt.Println(err)
	       } else {
	           fmt.Println(employeeInfo.id, employeeInfo.name, employeeInfo.salary)
	       }
	   }
	*/

}

func (self *Dao) InsertXX() {
	sql := "INSERT INTO users values(?,?,?)"
	rs, err := self.db.Exec(sql, 4, "yyy", 1000)
	if err != nil {
		fmt.Println(err)
		return
	}
	if id, _ := rs.LastInsertId(); id > 0 {
		fmt.Println("insert success")
	}
	/*也可以这样判断是否插入成功
	  if n,_ := rs.RowsAffected();n > 0 {
	      fmt.Println("insert success")
	  }
	*/
}

//Prepared Statements
//select,insert,update,delete
func (self *Dao) PreparedStms() {
	stmt, err := self.db.Prepare("SELECT * FROM users WHERE id = ?")
	if err != nil {
		return
	}
	defer stmt.Close()
	rows, err := stmt.Query(2)
	defer rows.Close()
	for rows.Next() {
		var (
			id       int
			username string
			salary   int
		)
		err = rows.Scan(&id, &username, &salary)
		if err != nil {
			fmt.Println(err)
		} else {
			fmt.Println(id, username, salary)
		}

	}
}

//transactions
func (self *Dao) txOps() {
	tx, _ := self.db.Beginx()
	rs, err := tx.Exec("UPDATE users SET username = ? WHERE id = ?", "aaaa", 2)
	if err != nil {
		fmt.Println(err)
	}
	err = tx.Commit()
	if err != nil {
		fmt.Println(err)
	}
	if n, _ := rs.RowsAffected(); n > 0 {
		fmt.Println("txops success!")
	}

}
