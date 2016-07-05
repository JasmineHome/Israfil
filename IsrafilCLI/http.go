package main

import (
	//	"encoding/json"
	"fmt"
	"net/http"
	"strings"

	//"github.com/LER0ever/Israfil/base"
)

func ActSearch(Place string, Name string) (retws string) {
	//var tmpSR base.SearchRet
	/*switch Place {
	  case "universal":
	      tmpSR, err := ps[0].Search("Netease", Name)
	      if err!= nil {panic("Universal Netease Search err")}
	      strSR,_ := json.MarshalIndent(tmpSR,"","  ")
	      retws += "<h1>Netease Result</h1><br />"+string(strSR) + "<br /><br />"
	      tmpSR, err = ps[1].Search("QQMusic", Name)
	      if err!= nil {panic("Universal QQMusic Search Err")}
	      strSR, _ = json.MarshalIndent(tmpSR,"","  ")
	      retws += "<h1>QQMusic Result</h1><br />"+ string(strSR) + "<br /><br />"
	  default:
	      return "Not Supported Yet"
	  }*/
	retws = ""
	return retws
}

func Handler(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "<h1>Israfil Core Go V0.0.1<br />Not Working Yet</h1>")
	fmt.Fprintf(w, r.URL.Path)
	URLPaths := strings.Split(r.URL.Path, "/")
	fmt.Fprintf(w, "\nlen %d slice %q<br />", len(URLPaths), URLPaths)
	if len(URLPaths) == 4 && URLPaths[1] != "" {
		fmt.Fprintf(w, "passed")
		switch URLPaths[1] {
		case "search":
			fmt.Fprintf(w, ActSearch(URLPaths[2], URLPaths[3]))
		default:
			fmt.Fprintf(w, "Not Supported Yet")
		}
	} else {
		fmt.Fprintf(w, "Welcome to IsrafilCore HTTP API<br />"+
			"Here is some basic usage examples: <br />"+
			"/search/universal/Victory for search songs<br />"+
			"/download/netease/ID for download songs from netease <br />"+
			"/download/universal/UID for download songs by UID across different sources <br />")
	}
}

func StartHTTPAPI() {
	fmt.Printf("Started HTTP Server at Port 8080")
	http.HandleFunc("/", Handler)
	http.ListenAndServe(":8080", nil)
}
