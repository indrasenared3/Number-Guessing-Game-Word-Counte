import random
from collections import Counter
import os

def number_guessing_game():
    print("\n--- Number Guessing Game ---")
    target = random.randint(1, 100)
    attempts = 0
    print("I have chosen a secret number between 1 and 100. Try to guess it!")
    
    while True:
        try:
            guess = int(input("Enter your guess: "))
            attempts += 1
            
            if guess < target:
                print("Too low! Try again.")
            elif guess > target:
                print("Too high! Try again.")
            else:
                print(f"Congratulations! You guessed the number in {attempts} attempts.")
                # Scoring system: starts at 100 and loses 5 points per extra attempt
                score = max(10, 100 - (attempts - 1) * 5)
                print(f"Your Score: {score}/100")
                break
        except ValueError:
            print("Invalid input. Please enter a valid integer.")

def word_counter_tool():
    print("\n--- Word Frequency Counter ---")
    filename = input("Enter the text file name (e.g., sample.txt): ").strip()
    
    # Automatically create a sample file if it doesn't exist so the script runs smoothly
    if not os.path.exists(filename):
        print(f"'{filename}' not found. Creating a sample text file for you...")
        with open(filename, "w", encoding="utf-8") as f:
            f.write("Python is an amazing programming language. Python is widely used in data science, web development, and automation. Programming in Python is fun and powerful!")
        print(f"Created '{filename}' with sample text.")

    try:
        with open(filename, "r", encoding="utf-8") as file:
            text = file.read()
            
        # String manipulation: convert to lowercase and split into words
        words = text.lower().split()
        cleaned_words = [word.strip(".,!?\"'()") for word in words]
        
        word_count = len(cleaned_words)
        frequency = Counter(cleaned_words)
        
        print(f"\n--- Analysis Results for '{filename}' ---")
        print(f"Total words found: {word_count}")
        print("Top 5 Most Common Words:")
        for word, count in frequency.most_common(5):
            print(f"  - '{word}': {count} time(s)")
            
    except Exception as e:
        print(f"An error occurred while reading the file: {e}")

def main():
    while True:
        print("\n==============================")
        print("   INTERNSHIP TASK 2 MENU     ")
        print("==============================")
        print("1. Play Number Guessing Game")
        print("2. Run Word Frequency Counter")
        print("3. Exit")
        
        choice = input("Select an option (1-3): ").strip()
        
        if choice == '1':
            number_guessing_game()
        elif choice == '2':
            word_counter_tool()
        elif choice == '3':
            print("Exiting program. Good luck with your submission!")
            break
        else:
            print("Invalid choice. Please select 1, 2, or 3.")

if __name__ == "__main__":
    main()