def get_formatted_name(first: str, last: str, middle=None)->str:
    full_name = f'{first} {middle} {last}' if middle else f'{first} {last}'
    return full_name.title()