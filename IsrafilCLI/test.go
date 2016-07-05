package main

import (
	"fmt"
	"io/ioutil"
	"net/http"
	"strings"

	"github.com/LER0ever/Israfil/IsrafilCLI/universal"
)

func testUniSearch() {
	fmt.Println(universal.Search("soledad", 1))
}

func testNeteaseSearch(key string) string {
	arg := fmt.Sprintf("type=1&s=%s&offset=0&limit=30", key)

	client := &http.Client{}
	req, err := http.NewRequest("POST", "http://music.163.com/api/search/get/web", strings.NewReader(arg))
	req.Header.Set("Content-Type", "application/x-www-form-urlencoded")
	req.Header.Set("Referer", "http://music.163.com/")
	resp, err := client.Do(req)
	defer resp.Body.Close()
	if err != nil {
		fmt.Println(err)
	}
	body, err := ioutil.ReadAll(resp.Body)
	return string(body)
}
