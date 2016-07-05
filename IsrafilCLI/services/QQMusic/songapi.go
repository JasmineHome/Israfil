package qqmusic

import (
	"encoding/json"
	"fmt"
	"log"
	"strings"

	"github.com/ddliu/go-httpclient"
)

func InitHTTPClient() {
	httpclient.Defaults(httpclient.Map{
		httpclient.OPT_USERAGENT: "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/48.0.2564.103 Safari/537.36",
		"Accept":                 "*/*",
		"Accept-Encoding":        "gzip,deflate,sdch",
		"Accept-Language":        "en-us",
		"Connection":             "keep-alive",
		"Content-Type":           "application/x-www-form-urlencoded",
		"Host":                   "http://y.qq.com/",
		"Referer":                "http://y.qq.com/",
		"User-Agent":             "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/48.0.2564.103 Safari/537.36",
	})
}

func testRequests() string {
	res, _ := httpclient.Get("http://headers.cloxy.net/request.php", nil)
	restr, _ := res.ToString()
	//log.Printf("%s", res.ToString())
	return restr
}

func splitF(FString string) []string {
	return strings.Split(FString, "|")
}

func searchByName(Name string, Qmsr *QMSearchRet) error {
	resp, err := httpclient.Get(fmt.Sprintf(QMSearchURL, 20, Name), nil)
	if err != nil {
		log.Fatalf("QM http get err: %s", err)
		return err
	}
	content, _ := resp.ReadAll()
	err = json.Unmarshal(content, Qmsr)
	if err != nil {
		log.Fatalf("Json Parse err: ", err)
		return err
	}
	return nil
}
