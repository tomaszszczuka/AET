/*
 * debug.h
 *
 *  Modified on: 24 Jul 2017
 *      By: Tomasz Szczuka
 *
 *      Based almost entirely on Mike Stirling's ANSI.h and common.h
 *      http://www.mike-stirling.com
 */

#ifndef DEBUG_H_
#define DEBUG_H_

// ***************************** ANSI definitions **************
//! Move the cursor up one row
#define CURSOR_UP		"\033[A"
//! Move the cursor down one row
#define CURSOR_DOWN		"\033[B"
//! Move the cursor forward one column
#define CURSOR_RIGHT	"\033[C"
//! Move the cursor back one column
#define CURSOR_LEFT		"\033[D"

//! Move the cursor to the start of the next row
#define CURSOR_NL		"\033[E"
//! Move the cursor to the start of the previous row
#define CURSOR_PL		"\033[F"

//! Move the cursor to the specified column (1 based)
#define CURSOR_COL		"\033[%dG"
//! Move the cursor to the specified row,column (1 based)
#define CURSOR_MOVE		"\033[%d;%dH"

//! Save the current cursor position
#define CURSOR_SAVE		"\033[s"
//! Move the cursor to the last saved position
#define CURSOR_RESTORE	"\033[u"

//! Clear from the cursor to the end of the screen
#define CLEAR_AFTER		"\033[0J"
//! Clear from the cursor to the start of the screen
#define CLEAR_BEFORE	"\033[1J"
//! Clear the entire screen
#define CLEAR_SCREEN	"\033[2J"

//! Clear from the cursor to the end of the line
#define CLEAR_EOL		"\033[0K"
//! Clear from the cursor to the start of the line
#define CLEAR_SOL		"\033[1K"
//! Clear the current line
#define CLEAR_LINE		"\033[2K"

//! Scroll the page up one line, adding a blank line at the bottom
#define SCROLL_UP		"\033[S"
//! Scroll the page up n lines, adding blanks at the bottom
#define SCROLL_UPn		"\033[%dS"
//! Scroll the page down one line, adding a blank line at the top
#define SCROLL_DOWN		"\033[T"
//! Scroll the page down n lines, adding blanks at the bottom
#define SCROLL_DOWNn	"\033[%dT"

//! Reset all attributes to defaults
#define ATTR_RESET		"\033[0m"
//! Select normal character weight
#define ATTR_NORMAL		"\033[22m"
//! Select bright text (sometimes rendered as bold)
#define ATTR_BRIGHT		"\033[1m"
//! Select dim text (not necessarily supported)
#define ATTR_DIM		"\033[2m"
//! Select italic text
#define ATTR_ITALIC		"\033[3m"
//! Select underlining
#define ATTR_UNDERLINE	"\033[4m"
//! Enable slow blink
#define ATTR_BLINK		"\033[5m"
//! Enable fast blink
#define ATTR_FASTBLINK	"\033[6m"
//! Cancel blinking
#define ATTR_STEADY		"\033[25m"
//! Select inverse polarity text
#define ATTR_INVERSE	"\033[7m"
//! Select normal polarity text
#define ATTR_POSITIVE	"\033[27m"

//! Set foreground colour: black
#define FG_BLACK		"\033[30m"
//! Set foreground colour: red
#define FG_RED			"\033[31m"
//! Set foreground colour: green
#define FG_GREEN		"\033[32m"
//! Set foreground colour: yellow
#define FG_YELLOW		"\033[33m"
//! Set foreground colour: blue
#define FG_BLUE			"\033[34m"
//! Set foreground colour: magenta
#define FG_MAGENTA		"\033[35m"
//! Set foreground colour: cyan
#define FG_CYAN			"\033[36m"
//! Set foreground colour: white
#define FG_WHITE		"\033[37m"
//! Set foreground colour: reset to default
#define FG_RESET		"\033[39m"

//! Set background colour: black
#define BG_BLACK		"\033[40m"
//! Set background colour: red
#define BG_RED			"\033[41m"
//! Set background colour: green
#define BG_GREEN		"\033[42m"
//! Set background colour: yellow
#define BG_YELLOW		"\033[43m"
//! Set background colour: blue
#define BG_BLUE			"\033[44m"
//! Set background colour: magenta
#define BG_MAGENTA		"\033[45m"
//! Set background colour: cyan
#define BG_CYAN			"\033[46m"
//! Set background colour: white
#define BG_WHITE		"\033[47m"
//! Set background colour: reset to default
#define BG_RESET		"\033[49m"

// ***************************** ANSI definitions **************

#define DEBUG_LVL 2

// ***************************** debug macros **************
#if DEBUG_LVL
#include <stdio.h>
#include <stdint.h>
#endif

#define HDR_MSG(a,...)			{ fprintf(stderr,ATTR_RESET FG_WHITE __FILE__ "(%d): " ATTR_RESET a,__LINE__,##__VA_ARGS__); }

#if DEBUG_LVL > 1
//! Outputs red debug messages when debug level is 1 or more
#define ERROR(a,...)			{ fprintf(stderr,ATTR_RESET FG_RED __FILE__ "(%d): " ATTR_RESET a,__LINE__,##__VA_ARGS__); }
#else
#define ERROR(...)
#endif

#if DEBUG_LVL > 1
//! Outputs yellow debug messages when debug level is 2 or more
#define INFO(a,...)				{ fprintf(stderr,ATTR_RESET FG_GREEN __FILE__ "(%d): " ATTR_RESET a,__LINE__,##__VA_ARGS__); }
#else
#define INFO(...)
#endif

#if DEBUG_LVL > 2
//! Outputs green debug messages when debug level is 3 or more
#define TRACE(a,...)			{ fprintf(stderr,ATTR_RESET FG_YELLOW __FILE__ "(%d): " ATTR_RESET a,__LINE__,##__VA_ARGS__); }
#else
#define TRACE(...)
#endif

#if DEBUG_LVL > 3
//! Intended for use in ISRs, outputs cyan debug messages when debug level is 4 or more
#define ISR_TRACE(a,...)		{ fprintf(stderr,ATTR_RESET FG_CYAN __FILE__ "(%d): " ATTR_RESET a,__LINE__,##__VA_ARGS__); }
#else
#define ISR_TRACE(...)
#endif

#define FUNCTION_TRACE			TRACE("%s\n", __FUNCTION__)
#define ARRAY_SIZE(n)			(sizeof(n) / sizeof(n[0]))
#define PACKED					__attribute__((packed)

// ***************************** debug macros **************

// ***************************** function prototypes **************
#include  <errno.h>
#include  <sys/unistd.h> // STDOUT_FILENO, STDERR_FILENO

// ***************************** function prototypes **************

#endif /* DEBUG_H_ */
