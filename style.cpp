#include <stdio.h>

#define RESET           "\x1b[0m"
#define BLACK           "\x1b[30m"
#define RED             "\x1b[31m"
#define GREEN           "\x1b[32m"
#define YELLOW          "\x1b[33m"
#define BLUE            "\x1b[34m"
#define MAGENTA         "\x1b[35m"
#define CYAN            "\x1b[36m"
#define WHITE           "\x1b[37m"
#define BRIGHT_BLACK    "\x1b[90m"
#define BRIGHT_RED      "\x1b[91m"
#define BRIGHT_GREEN    "\x1b[92m"
#define BRIGHT_YELLOW   "\x1b[93m"
#define BRIGHT_BLUE     "\x1b[94m"
#define BRIGHT_MAGENTA  "\x1b[95m"
#define BRIGHT_CYAN     "\x1b[96m"
#define BRIGHT_WHITE    "\x1b[97m"

#define BOLDBLACK       "\x1b[1m\x1b[30m"
#define BOLDRED         "\x1b[1m\x1b[31m"
#define BOLDGREEN       "\x1b[1m\x1b[32m"
#define BOLDYELLOW      "\x1b[1m\x1b[33m"
#define BOLDBLUE        "\x1b[1m\x1b[34m"
#define BOLDMAGENTA     "\x1b[1m\x1b[35m"
#define BOLDCYAN        "\x1b[1m\x1b[36m"
#define BOLDWHITE       "\x1b[1m\x1b[37m"
#define BRIGHT_BOLDBLACK    "\x1b[1m\x1b[90m"
#define BRIGHT_BOLDRED      "\x1b[1m\x1b[91m"
#define BRIGHT_BOLDGREEN    "\x1b[1m\x1b[92m"
#define BRIGHT_BOLDYELLOW   "\x1b[1m\x1b[93m"
#define BRIGHT_BOLDBLUE     "\x1b[1m\x1b[94m"
#define BRIGHT_BOLDMAGENTA  "\x1b[1m\x1b[95m"
#define BRIGHT_BOLDCYAN     "\x1b[1m\x1b[96m"
#define BRIGHT_BOLDWHITE    "\x1b[1m\x1b[97m"

#define UNDERLINE       "\x1b[4m"
#define INVERSE         "\x1b[7m"
#define BOLD            "\x1b[1m"
#define ITALIC          "\x1b[3m"
#define FAINT           "\x1b[2m"
#define STRIKETHROUGH   "\x1b[9m"
#define BLINK           "\x1b[5m"
#define RAPID_BLINK     "\x1b[6m"
#define HIDDEN          "\x1b[8m"

int main() {
    printf("This is " RED "red" RESET " text.\n");
    printf("This is " GREEN "green" RESET " text.\n");
    printf("This is " YELLOW "yellow" RESET " text.\n");
    printf("This is " BLUE "blue" RESET " text.\n");
    printf("This is " MAGENTA "magenta" RESET " text.\n");
    printf("This is " CYAN "cyan" RESET " text.\n");
    printf("This is " WHITE "white" RESET " text.\n");
    printf("This is " BRIGHT_BLACK "bright black" RESET " text.\n");
    printf("This is " BRIGHT_RED "bright red" RESET " text.\n");
    printf("This is " BRIGHT_GREEN "bright green" RESET " text.\n");
    printf("This is " BRIGHT_YELLOW "bright yellow" RESET " text.\n");
    printf("This is " BRIGHT_BLUE "bright blue" RESET " text.\n");
    printf("This is " BRIGHT_MAGENTA "bright magenta" RESET " text.\n");
    printf("This is " BRIGHT_CYAN "bright cyan" RESET " text.\n");
    printf("This is " BRIGHT_WHITE "bright white" RESET " text.\n");

    printf("This is " BOLDRED "bold red" RESET " text.\n");
    printf("This is " BOLDGREEN "bold green" RESET " text.\n");
    printf("This is " BOLDYELLOW "bold yellow" RESET " text.\n");
    printf("This is " BOLDBLUE "bold blue" RESET " text.\n");
    printf("This is " BOLDMAGENTA "bold magenta" RESET " text.\n");
    printf("This is " BOLDCYAN "bold cyan" RESET " text.\n");
    printf("This is " BOLDWHITE "bold white" RESET " text.\n");
    printf("This is " BRIGHT_BOLDRED "bright bold red" RESET " text.\n");
    printf("This is " BRIGHT_BOLDGREEN "bright bold green" RESET " text.\n");
    printf("This is " BRIGHT_BOLDYELLOW "bright bold yellow" RESET " text.\n");
    printf("This is " BRIGHT_BOLDBLUE "bright bold blue" RESET " text.\n");
    printf("This is " BRIGHT_BOLDMAGENTA "bright bold magenta" RESET " text.\n");
    printf("This is " BRIGHT_BOLDCYAN "bright bold cyan" RESET " text.\n");
    printf("This is " BRIGHT_BOLDWHITE "bright bold white" RESET " text.\n");

    printf("This is " UNDERLINE "underlined" RESET " text.\n");
    printf("This is " INVERSE "inversed" RESET " text.\n");
    printf("This is " BOLD "bold" RESET " text.\n");
    printf("This is " ITALIC "italic" RESET " text.\n");
    printf("This is " FAINT "faint" RESET " text.\n");
    printf("This is " STRIKETHROUGH "strikethrough" RESET " text.\n");
    printf("This is " BLINK "blinking" RESET " text.\n");
    printf("This is " RAPID_BLINK "rapidly blinking" RESET " text.\n");
    printf("This is " HIDDEN "hidden" RESET " text.\n");

    return 0;
}
