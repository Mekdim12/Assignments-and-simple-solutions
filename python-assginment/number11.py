

class WordWithLetterAFinder:
    def __init__(self, words_file_path):
        self.words_file_path = words_file_path
        self.file_reader() 
    
    def file_reader(self):
        try:
            #  read the files and split the words using new line
            with open(self.words_file_path, "r") as file:
                self.words = file.read().split()
        except FileNotFoundError as e:
            print("kkkk", e)
            print("Words File not found")
            exit()
        
    def words_with_letter_a_file_writer(self, list_of_words_with_letter_a):
        #  write the words with letter a to a file
        with open("a.txt", "w") as file:
            file.write("\n".join(list_of_words_with_letter_a))
    
    def words_with_letter_a_collector(self):
        list_of_words_with_letter_a = []
        for word in self.words:
            if str(word).strip().lower().startswith("a"):
                list_of_words_with_letter_a.append(word)
        self.words_with_letter_a_file_writer(list_of_words_with_letter_a)


if __name__ == "__main__":
    words_with_letter_a = WordWithLetterAFinder("words.txt")
    words_with_letter_a.words_with_letter_a_collector()