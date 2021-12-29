package main

import (
	"fmt"
	"log"
	"net/http"
)

func main() {
	// without custom mux server
	// http.ListenAndServe(":3000", nil)

	// with custom mux server
	// mux := http.NewServeMux()
	// mux.HandleFunc("/", path_handler.IndexPathHandler)
	// mux.HandleFunc("/bar", barhandler.BarHandler)
	// http.ListenAndServe(":3000", mux)

	// Handler static file
	// http.Handle("/html/", http.StripPrefix("/html/", http.FileServer(http.Dir("./html"))))
	// http.ListenAndServe(":3000", nil)

	// json handler
	// mux := json_handler.MakeWebHandler()
	// http.ListenAndServe(":3001", mux)

	// https handler

	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		fmt.Fprint(w, "Hello World")
	})

	err := http.ListenAndServeTLS(":3000", "localhost.crt", "localhost.key", nil)

	if err != nil {
		log.Fatal(err)
	}
}
