// ****************************************************************************
//  unsubsquirrel.c                                        Unsubquirrel project
// ****************************************************************************
//
//   File Description:
//
//     This program teaches your how to unsubsquirrel.
//
//
//
//
//
//
//
//
// ****************************************************************************
//   (C) 2019 Christophe de Dinechin <christophe@dinechin.org>
//   This software is licensed under the GNU General Public License v3
// ****************************************************************************
//   This file is part of Unsubquirrel.
//
//   Unsubquirrel is free software: you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//
//   Unsubquirrel is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public License
//   along with Unsubquirrel.  If not, see <https://www.gnu.org/licenses/>.
// ****************************************************************************

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

void sep_line(size_t howmany, char begin, char c, char end)
// ----------------------------------------------------------------------------
//    DRY paranoia
// ----------------------------------------------------------------------------
{
    putchar(' ');
    putchar(begin);
    while (howmany--)
        putchar(c);
    putchar(end);
    putchar('\n');
}


int main(int argc, const char **argv)
// ----------------------------------------------------------------------------
//   Talking unsubsquirrel
// ----------------------------------------------------------------------------
{
    if (argc < 2)
    {
        static const char *default_messages[] =
        {
            "Netiquette is apparently a hard nut to crack",
            "Unsubscribe you? You can't be serious!",
            "Nack",
            "We are sorry to not see you leave",
            "Please be considerate and do post this to another list",
            "Have you considered cross-posting this to world-list@gmail.com?",
            "Access denied: Problem between keyboard and chair (E_PBKAC)",
            "Fwd: Blog post: 7 tips for remote-work sanity",
            "What about a cup of tea?",
            "You are probably not remote enough"
        };
        struct timeval tv;
        gettimeofday(&tv, NULL);
        srandom(tv.tv_sec + tv.tv_usec);
        argc = sizeof(default_messages) / sizeof(default_messages[0]);
        argv = default_messages - 1 + random() % argc;
        argc = 2;
    }

    size_t max_len = 0;
    int a;
    for (a = 1; a < argc; a++)
    {
        size_t len = strlen(argv[a]);
        if (max_len < len)
            max_len = len;
    }
    if (max_len < 15)
        max_len = 15;
    sep_line(max_len, '/', '-', '\\');
    for (a = 1; a < argc; a++)
        printf("| %-*s |\n", (int) max_len, argv[a]);
    sep_line(max_len, '\\', '-', '/');
    printf(/* Courtesy Olaf Bohlen */
        "          \\\n"
        "           \\              .-'` `}\n"
        "            \\    _./)   /       }\n"
        "                .'o   \\ |       }\n"
        "                '.___.'`.\\    {`\n"
        "                /`\\_/  , `.    }\n"
        "                \\=' .-'   _`\\  {\n"
        "                 `'`;/      `,  }\n"
        "                    _\\       ;  }\n"
        "          jgs      /__`;-...'--'\n");
}
