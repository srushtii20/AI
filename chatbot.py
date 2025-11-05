def simple_chatbot():
    print("Bot: Hello! Welcome to our restaurant.")
    
    while True:
        user_input = input("You: ").lower()
        
        if "hi" in user_input or "hello" in user_input:
            print("Bot: Hello! How can I help you?")
        
        elif "menu" in user_input:
            print("Bot: We have Pizza, Pasta, Burger, and Salad.")
        
        elif "book" in user_input or "reservation" in user_input:
            print("Bot: Your table is booked!")
        
        elif "bye" in user_input:
            print("Bot: Goodbye! Have a nice day!")
            break
        
        else:
            print("Bot: Sorry, I can only help with menu or booking.")

# Run chatbot
simple_chatbot()
