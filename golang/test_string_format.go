package main

import "fmt"

func main() {
    sql := `SELECT ad_app_id, pull_type, sum_active_uv_1, sum_click_pv_1, sum_exposure_pv_1 / sum_exposure_pv AS rate
            FROM (
                SELECT ad_app_id, pull_type, SUM(active_uv) AS sum_active_uv_1, SUM(click_pv) AS sum_click_pv_1, SUM(exposure_pv) AS sum_exposure_pv_1
                FROM t_stat_medium_ad
                WHERE data_date = (
                    SELECT MAX(data_date)
                    FROM t_stat_medium_ad
                )
                GROUP BY ad_app_id, pull_type
            ) t1
            INNER JOIN (
                SELECT SUM(exposure_pv) AS sum_exposure_pv
                FROM t_stat_medium_ad
                WHERE data_date = ( SELECT MAX(data_date) FROM t_stat_medium_ad)
            ) t2 ON 1 = 1; `
    
    
}

