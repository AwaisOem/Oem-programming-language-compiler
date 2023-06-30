#include<bits/stdc++.h>
using namespace std;
namespace constants{
    const char * delimiters = "\n\t\r :;,()" ;
    const char * whiteSpace = "\n\t\r "; 
    enum Lexemes{
        IDENTIFIER , 
        KEYWORD , 
        OPERATOR , 
        LITERAL , 
        COMMENT , 
        PUNCTUATOR , 
        END_OF_FILE
    };
    const string keywords[] = {
        "let" ,
        "int" , 
        "float" ,
        "double" ,
        "char" ,
        "string" ,
        "bool" ,
        "if" ,
        "else" ,
        "for" ,
        "while" ,
        "do" ,
        "break" ,
        "continue" ,
        "return" ,
        "switch" ,
        "case" ,
        "default" ,
        "true" ,
        "false" ,
        "null" ,
        "void",
        "print" ,
        "read" ,
        "readln"
    };
};
class Error {
    public:
    static enum { 
        INVALID_INPUT ,
        LEXER_ERROR , 
        PARSER_ERROR , 
        SEMANTIC_ERROR , 
        CODE_GENERATION_ERROR , 
        INTERMEDIATE_CODE_GENERATION_ERROR , 
        OPTIMIZATION_ERROR , 
        EXECUTION_ERROR , 
        COMPILER_ERROR,
        ERROR
    } ERROR_TYPE;
    Error(const char * message , int type){
        string error = "\033[31m";
        switch(type){
            case INVALID_INPUT:
            error += "INVALID INPUT";
            break;
            case LEXER_ERROR:
            error += "LEXER ERROR";
            break;
            case PARSER_ERROR:
            error += "PARSER ERROR";
            break;
            case SEMANTIC_ERROR:
            error += "SEMANTIC ERROR";
            break;
            case CODE_GENERATION_ERROR:
            error += "CODE GENERATION ERROR";
            break;
            case INTERMEDIATE_CODE_GENERATION_ERROR:
            error += "INTERMEDIATE CODE GENERATION ERROR";
            break;
            case OPTIMIZATION_ERROR:
            error += "OPTIMIZATION ERROR";
            break;
            case EXECUTION_ERROR:
            error += "EXECUTION ERROR";
            break;
            case COMPILER_ERROR:
            error += "COMPILER ERROR";
            break;
            default:
            error += "ERROR";
        }
        error += ": "+string(message)+"\033[0m\n";
        throw error;
    }
};

class ReadFile{
    char * content;
    long size; 
    public:
    ReadFile(char *path){
        fstream file;
        file.open(path , ios::in);
        if(!file){
            char message[] = "File not found at path:";
            strcat(message , path);
            Error(message , Error::INVALID_INPUT);
        }
        file.seekg(0 , ios::end);
        size = file.tellg();
        file.seekg(0 , ios::beg);
        content = new char[size];
        file.read(content , size);
        file.close();
    }
    char * get_content(){
        return content;
    }
    long get_size(){
        return size;
    }
    ~ReadFile(){
        delete content;
    }
};
class Lexer{
    char * sorceCode;
    map<string ,int> keywords;
    public:
    Lexer(char * content){
        content += strspn(content, constants::whiteSpace);
        sorceCode = content;
        cout<<sorceCode<<endl;
    }
    void Lex(){
        // Build Lexer for the language
        // 1. Identify the tokens
        // 2. Identify the lexemes
        // 3. Identify the keywords
        // 4. Identify the punctuators
        // 5. Identify the operators
        // 6. Identify the literals
        // 7. Identify the identifiers
        // 8. Identify the comments
        // 9. Identify the end of file
        // 10. Identify the white spaces
        // 11. Identify the new lines
        // 12. Identify the tabs
        // 13. Identify the carriage returns
        // 14. Identify the colons
        // 15. Identify the semicolons
        // 16. Identify the commas
        // 17. Identify the brackets
        // 18. Identify the braces
        // 19. Identify the parenthesis

        //Building Tokens
        for(int = 0;sorceCode[i]!='\0';i++){
            if("/*" == sorceCode[i]+sorceCode[i+1]){
                while(sorceCode[i]!='\0' && "*/" != sorceCode[i]+sorceCode[i+1])
                    i++;
            }
        else if('//' == sourceCode[i]+sorceCode[i+1])
        {
                while(sorceCode[i]!='\0' && '\n' != sorceCode[i])
                i++;
        }
          

        }

        
    }
    int is_identi(int i){
        if(is_valid_first_character(sorceCode[i])){
            i++;
            while(is_valid_identifier(sorceCode[i])){
                i++;
            }
            return true;
        }
        return false;
    }
    }
    bool is_valid_identifier(char * identifier){
        return is_valid_first_character(identifier[0]) && strpbrk(identifier , constants::delimiters) == NULL;
    }
    bool is_valid_first_character(const char &name){
        return (name>='a' && name <='z' )  ||  
        (name>='A' && name <='Z' ) || name== '_';
    }

};
class Parser{
    public:
    Parser(){
        cout<<"Parser"<<endl;
    }
    void Parse(){
        cout<<"Parsing"<<endl;
    }
};
class Compiler{
    char * content;
    public:
    Compiler(char * c){
        content = new char[strlen(c)];
        strcpy(content , c);
    }
    void Compile(){
        Lex();
    }
    void CodeGen(){
        cout<<"Code Generation"<<endl;
    }
    void Intermedite(){
        cout<<"Intermedite Code Generation"<<endl;
    }
    void Optimize(){
        cout<<"Optimization"<<endl;
    }
    void Execute(){
        cout<<"Executing"<<endl;
    }
    void Lex(){
        Lexer  * lexer = new Lexer(content);
        cout<<content<<endl;
        lexer->Lex();
    }   
    void Parse(){
        Parser* parser = new Parser();
        parser->Parse();
    }
    ~Compiler(){
        delete content;
    }
};
int main(int args , char ** argv )
{
    try{
        if(args  < 2){
            char  message[] = "No input Files\n Syntax:: ";
            strcat(message , argv[0]);
            strcat(message , " <path to program file>");
            Error(message, Error::ERROR);
        }
        ReadFile *file = new ReadFile(argv[1]);
        Compiler *compiler = new Compiler(file->get_content());
        compiler->Compile();



        delete compiler;
        delete file;
    }catch(const string &error){
        cout<<error<<endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}