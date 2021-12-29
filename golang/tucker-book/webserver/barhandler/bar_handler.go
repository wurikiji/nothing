package barhandler

import (
	"fmt"
	"net/http"
	"strconv"
)

func init() {
	http.HandleFunc("/bar", BarHandler)
}

func BarHandler(w http.ResponseWriter, r *http.Request) {
	values := r.URL.Query()
	name := values.Get("name")
	if name == "" {
		name = "World"
	}
	id, _ := strconv.Atoi(values.Get("id"))
	fmt.Fprintf(w, "Hello %s! id: %d\n", name, id)
}
