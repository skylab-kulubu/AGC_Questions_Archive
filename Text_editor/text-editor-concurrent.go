package main

import (
	"strings"
	"sync"
	"unicode"
)

// checkWordLength reports whether a word is longer than 7 characters.
func checkWordLength(w string) int {
	if len(w) > 7 {
		return 1
	}
	return 0
}

// checkVowels reports whether a word has consecutive vowels or not.
// Returns the number of consecutive vowel pairs.
func checkVowels(w string) (errorCnt int) {
	vowels := "aeiouAEIOU"

	for i := range len(w) - 1 {
		j := i + 1
		if strings.ContainsRune(vowels, rune(w[i])) && strings.ContainsRune(vowels, rune(w[j])) {
			errorCnt++
		}
	}
	return errorCnt
}

// checkWordCount reports whether a sentence has more than 4 words.
func checkWordCount(w []string) int {
	if len(w) > 4 {
		return 1
	}
	return 0
}

// checkParagraphs reports whether a given paragraph has more than 30 words.
func checkParagraph(p string) int {
	if len(strings.Fields(p)) > 30 {
		return 1
	}
	return 0
}

// TextEditorConcurrent checks a paragraph concurrently whether it satisfies conditions below:
//   - Paragraph has less than or equal to 30 words.
//   - Each sentence in paragraph has 4 or less words.
//   - Each word has 7 or less characters.
//   - Neither word has two or more consecutive vowels.
//
// If a paragraph has words and/or sentences not satisfying the conditions, returns the amount of errors made.
func TextEditorConcurrent(p string) (errors int) {
	var wg sync.WaitGroup
	errCh := make(chan int)

	wg.Add(1)
	go func() {
		defer wg.Done()
		errCh <- checkParagraph(p)
	}()

	sentences := strings.Split(p, ".")

	for _, s := range sentences {
		sTrimmed := strings.TrimSpace(s)
		if sTrimmed == "" {
			continue
		}
		words := strings.Fields(sTrimmed)

		wg.Add(1)
		go func() {
			defer wg.Done()
			errCh <- checkWordCount(words)
		}()

		for _, w := range words {
			w := strings.TrimFunc(w, func(r rune) bool {
				return !unicode.IsLetter(r)
			})

			wg.Add(1)
			go func() {
				defer wg.Done()
				errCh <- checkWordLength(w)
			}()

			wg.Add(1)
			go func() {
				defer wg.Done()
				errCh <- checkVowels(w)
			}()
		}
	}

	go func() {
		wg.Wait()
		close(errCh)
	}()

	for err := range errCh {
		errors += err
	}

	return errors
}
