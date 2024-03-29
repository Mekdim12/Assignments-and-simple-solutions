class PalindromeWords:
    def __init__(self, words_file_path):
        self.words_file_path = words_file_path
        self.file_reader()

    def file_reader(self):
        try:
            #  read the files and split the words using new line
            with open(self.words_file_path, "r") as file:
                self.words = file.read().split()
        except FileNotFoundError:
            print("WordsFile not found")
            exit()

    def is_palindrome(self, word):
        if word == word[::-1]:
            return True

        return False

    def palindrome_words_file_writer(self, list_of_palindromes):
        #  write the palindrome words to a file
        with open("palindrome_words.txt", "w") as file:
            for word in list_of_palindromes:
                file.write(word + "\n")

    def palindrome_word_collector(self):
        list_of_palindrome_words = []
        for word in self.words:
            if self.is_palindrome(word):
                list_of_palindrome_words.append(word)
        self.palindrome_words_file_writer(list_of_palindrome_words)


if __name__ == "__main__":
    palindrome_words = PalindromeWords("words.txt")
    palindrome_words.palindrome_word_collector()