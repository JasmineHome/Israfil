package main

import (
    "fmt"
	"log"
	"net/url"
	"strings"
    "encoding/json"

	"github.com/ddliu/go-httpclient"
)

func decryptURL(location string) string { //Ceasar Matrix Decrypt
	urlStr := location[1:]
	urllen := len(urlStr)
	rowNumber := int(location[0]) - '0'

	colNumber := urllen / rowNumber // basic column count: 34
	spareChar := urllen % rowNumber // count of rows that have 1 more column

	var length int
	//matrix := make([]string, 0)
	var matrix []string
	for i := 0; i < rowNumber; i++ {
		if i < spareChar {
			length = colNumber + 1
		} else {
			length = colNumber
		}

		matrix = append(matrix, urlStr[:length])
		urlStr = urlStr[length:]
	}

	urlStr = ""
	for i := 0; i < urllen; i++ {
		urlStr += string(matrix[i%rowNumber][i/rowNumber])
	}

	s, _ := url.QueryUnescape(urlStr)
	return strings.Replace(s, "^", "0", -1)
}

func initHTTPClient() {
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

func getXiamiToken() string {
	var XiamiToken string
	resp, err := httpclient.Get("http://m.xiami.com", nil)
	if err != nil {
		log.Fatalf("getXiamiToken Error: %s", err)
	}
	strresp, _ := resp.ToString()
	TokenFirstIndex := strings.Index(strresp, "var _xiamitoken = ")
	if TokenFirstIndex != -1 {
	    XiamiToken = strresp[TokenFirstIndex+19 : TokenFirstIndex+51]
	} else {
	    log.Fatalf("getXiamiToken ERROR: %s", "the webpage does not contain a valid _xiamitoken")
	}
	return XiamiToken
}

func searchByName(Name string, Xmsr *XiamiSongSearchRet) error{
    resp, err := httpclient.Get(fmt.Sprintf(XiamiSongSearchURL, Name), nil)
    if err != nil {
        log.Fatalf("Xiami SearchbyName ERROR: %s", err)
        return err
    }
    content,_ := resp.ReadAll()
    err = json.Unmarshal(content, Xmsr)
    if err != nil{
        log.Fatalf("Json Unmarshal ERROR: %s", err)
        return err
    }
    return nil
}
