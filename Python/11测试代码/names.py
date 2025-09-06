from name_function import get_formatted_name

def show_name():
    print('Enter "q" at any time to quit')
    while True:
        x = 0
        input_data = []
        while x <= 1:
            str = 'first' if x == 0 else 'last'
            input_str = input(f'\nPlease give me a {str} name')
            if input_str == "q":
                return
            input_data.append(input_str)
            x += 1
        formatted_name = get_formatted_name(input_data[0], input_data[1])
        print(f'\tNeatly formatted name: {formatted_name}.')
show_name()