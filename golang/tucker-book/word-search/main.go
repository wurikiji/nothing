package main

import (
	"bufio"
	"fmt"
	"os"
	"path/filepath"
	"strings"
)

func main() {
	if len(os.Args) < 3 {
		fmt.Println("Usage: ./find target path")
	}
	target := os.Args[1]
	paths := os.Args[2:]

	fmt.Println("찾을 단어:", target)

	files := getAllFiles(paths)
	ch := make(chan FindInfo)

	run(files, target, ch)

	printResults(ch, files)
}

func printResults(ch chan FindInfo, files []string) {
	count := 0
	for findInfo := range ch {
		count++
		if count == len(files) {
			break
		}
		fmt.Println("---- Found from ", findInfo.filename, "----")
		for _, line := range findInfo.lines {
			fmt.Printf("\t%5d \t%s\n", line.lineNo, line.line)
		}
		fmt.Println()
		fmt.Println()
	}
}

func run(files []string, target string, ch chan FindInfo) {
	for _, file := range files {
		go FindAllLines(file, target, ch)
	}
}

func getAllFiles(paths []string) []string {
	files := []string{}
	for _, path := range paths {
		newFiles, err := GetFileList(path)
		if err != nil {
			fmt.Printf("Path %s has no matching folder and files. err: %v", path, err)
		}
		files = append(files, newFiles...)
	}
	return files
}

type LineInfo struct {
	lineNo int
	line   string
}

type FindInfo struct {
	filename string
	lines    []LineInfo
}

func FindAllLines(path string, target string, ch chan FindInfo) {
	ch <- FindFromFile(path, target)
}

func GetFileList(path string) ([]string, error) {
	return filepath.Glob(path)
}

func FindFromFile(filepath string, target string) FindInfo {
	findInfo := FindInfo{filename: filepath}
	file, err := os.Open(filepath)
	defer file.Close()

	if err != nil {
		fmt.Println("Can not open file ", file, " - err: ", err)
		return findInfo
	}

	scanner := bufio.NewScanner(file)

	lineNo := 0
	for scanner.Scan() {
		lineNo++
		line := scanner.Text()
		if strings.Contains(line, target) {
			findInfo.lines = append(findInfo.lines, LineInfo{
				lineNo: lineNo,
				line:   line,
			})
		}
	}
	return findInfo
}
