package path_handler

import (
	"fmt"
	"net/http"
)

func init() {
	http.HandleFunc("/", IndexPathHandler)
}

func IndexPathHandler(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Hello World\n")
}
