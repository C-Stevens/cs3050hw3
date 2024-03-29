#include "../include/input_error.h"
#include "../include/graph.h"

int main(int argc, char** argv) {
    if(argc != 2) { // Read in one argument
        exit(INCORRECT_NUMBER_OF_COMMAND_LINE_ARGUMENTS);
    }
    FILE* input = fopen(argv[1], "r");
    if(input == NULL) {
        exit(FILE_FAILED_TO_OPEN);
    }
    
    int i,inputSize,count,v1,v2;
    fscanf(input, "%d\n", &inputSize);
    graph* g = createGraph(inputSize);
    
    for(i=0; i<inputSize; i++) {
        count = fscanf(input, "(%d,%d)\n", &v1, &v2);
        if(count == EOF) {
            if(ferror(input)) {
                exit(PARSING_ERROR_INVALID_CHARACTER_ENCOUNTERED);
            }
        } else if(count != 2) {
            exit(PARSING_ERROR_INVALID_FORMAT);
        }
        //TODO: Check for v1/v2 not being valid vertexes, maybe more?
        createEdge(g, v1, v2);
    }
    //printGraph(g); //DEBUG
    printf("Fingers crossed\n"); //DEBUG
    printDistancesFromOrigin(g);
    printf("Fingers uncrossed\n"); //DEBUG
    
    //TODO: Free the graph
    if(fclose(input) == EOF) {
        exit(FILE_FAILED_TO_CLOSE);
    }
    exit(EXIT_SUCCESS);
}
