package netease

import (
	//	"crypto/aes"
	"crypto/md5"
	//	"crypto/rsa"
	"encoding/base64"
	"encoding/json"
	"fmt"
	"log"
	"math/rand"
	"net/http"
	"strings"
	"time"

	//	"github.com/LER0ever/Israfil/Core-Go/base"
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
		"Host":                   "music.163.com",
		"Referer":                "http://music.163.com/search",
		"User-Agent":             "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/48.0.2564.103 Safari/537.36",
	})
}

func testRequests() string {
	res, _ := httpclient.Get("http://headers.cloxy.net/request.php", nil)
	restr, _ := res.ToString()
	//log.Printf("%s", res.ToString())
	return restr
}

func encryptID(dfsID int64) string {
	bMagic := []byte(magicKey)
	bSongID := []byte(fmt.Sprintf("%d", dfsID))
	bMagicLen := len(bMagic)
	for i, b := range bSongID {
		bSongID[i] = b ^ bMagic[i%bMagicLen]
	}
	mbSongID := md5.New()
	mbSongID.Write(bSongID)
	res := base64.StdEncoding.EncodeToString(mbSongID.Sum(nil))
	res = strings.Replace(res, "/", "_", -1)
	res = strings.Replace(res, "+", "-", -1)
	return res
}

func downloadURLByID(dfsID int64) string {
	r := rand.New(rand.NewSource(time.Now().UnixNano()))
	dldURL := fmt.Sprintf(NESongCDN, r.Intn(1)+1, encryptID(dfsID), dfsID)
	return dldURL
}

// 通过歌曲ID拉取歌曲详细信息
func getInfoByID(ID int64, Neslr *NeteaseSongListRet) error {
	resp, err := httpclient.Get(fmt.Sprintf(NESongInfo, ID), nil)
	if err != nil {
		log.Fatalf("Failed to perform http GET: %s", err)
		return err
	}
	content, _ := resp.ReadAll()
	err = json.Unmarshal(content, Neslr)
	if err != nil {
		log.Fatalf("Json Parse error : %s", err)
		return err
	}
	log.Printf("%d", Neslr.Songs[0].HMusic.DfsID)
	return nil
	//return string(content)
}

func searchByName(Name string, Nesr *NeteaseSearchRet) error {
	resp, err := httpclient.
		WithCookie(&http.Cookie{
			Name:  "appver",
			Value: "2.0.2",
		}).
		Post("http://music.163.com/api/search/get/web", map[string]string{
			"s":      Name,
			"limit":  "30",
			"total":  "true",
			"type":   "1",
			"offset": "0",
		})
	if err != nil {
		log.Fatalf("POST err: %s", err)
		return err
	}
	content, _ := resp.ReadAll()
	log.Printf("POST Return: %s", content)
	err = json.Unmarshal(content, Nesr)
	if err != nil {
		log.Fatalf("Json Parse Error: %s", err)
		return err
	}
	return nil

	//log.Printf("POST return:: \n%s", restr)
	//reqSearch, _ := http.NewRequest("POST", "http://music.163.com/api/search/get/", body)
}
