void scc::handle_goto(std::istringstream& iss) {
    // 1. Extract the target line number for the goto command.
    int target_line_number;
    iss >> target_line_number;
 
    // 2. Search the symbol table to see if the line number is already defined.
    int target_location = search_symbol_table(target_line_number, 'L');  // 'L' is used to signify line numbers
 
    // 3. If the target line number exists (backward reference), generate the BRANCH instruction.
    if (target_location != -1) {
        // Backward reference: directly use the location.
        memory[next_instruction_addr] = BRANCH * target_location;
        flags[next_instruction_addr] = -1;  // No need to flag since it's resolved
    } else {
        // Forward reference: generate a partial BRANCH instruction.
        memory[next_instruction_addr] = BRANCH * 0;  // Placeholder address (will be fixed later)
        flags[next_instruction_addr] = target_line_number;  // Flag with the target line number
    }
 
    // 4. Increment the instruction pointer to the next instruction.
    next_instruction_addr++;
}
