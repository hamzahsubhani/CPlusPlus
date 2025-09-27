#ifndef TOKEN_H
#define TOKEN_H




void tokenize_command(const string& command_str, char* args[], int max_args)
{
    int i = 0; // Argument index
    bool in_quotes = false;
    string current_arg = "";

    for (size_t j = 0; j < command_str.size() && i < max_args - 1; ++j)
    {
        char ch = command_str[j];

        if (ch == '"') // Toggle quote mode
        {
            in_quotes = !in_quotes;
        }
        else if (ch == ' ' && !in_quotes) // Argument separator
        {
            if (!current_arg.empty())
            {
                args[i] = new char[current_arg.size() + 1];
                strcpy(args[i], current_arg.c_str());
                current_arg.clear();
                i++;
            }
        }
        else
        {
            current_arg += ch; // Add character to current argument
        }
    }

    // Add the last argument if it exists
    if (!current_arg.empty() && i < max_args - 1)
    {
        args[i] = new char[current_arg.size() + 1];
        strcpy(args[i], current_arg.c_str());
        i++;
    }

    args[i] = NULL; // Null-terminate the argument list
}
