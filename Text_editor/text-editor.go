package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
	"unicode"
)

// TextEditorConcurrent checks a paragraph whether it satisfies conditions below:
//   - Paragraph has less than or equal to 30 words.
//   - Each sentence in paragraph has 4 or less words.
//   - Each word has 7 or less characters.
//   - Neither word has two or more consecutive vowels.
//
// If a paragraph has words and/or sentences not satisfying the conditions, returns the amount of errors made.
func TextEditor(paragraph string) (errorCnt int) {
	if len(strings.Fields(paragraph)) > 30 {
		errorCnt++
	}

	sentences := strings.Split(paragraph, ".")

	for _, sentence := range sentences {
		sentence = strings.TrimSpace(sentence)
		if sentence == "" {
			continue
		}

		words := strings.Fields(sentence)

		if len(words) > 4 {
			errorCnt++
		}

		for _, word := range words {
			word = strings.TrimFunc(word, func(r rune) bool {
				return !unicode.IsLetter(r)
			})
			errorCnt += checkWordLength(word)
			errorCnt += checkVowels(word)
		}
	}

	return errorCnt
}

func main() {
	s := bufio.NewScanner(os.Stdin)
	s.Scan()
	p := s.Text()

	fmt.Println(TextEditor(p))
}
