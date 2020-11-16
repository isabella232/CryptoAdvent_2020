#!/usr/bin/env bash

COMMANDS=$(openssl help 2>&1 | sed -n '2,14p')

for COMMAND in $COMMANDS; do
    URL="https://www.openssl.org/docs/manmaster/man1/openssl-$COMMAND.html"
    DESCR=$(curl -s "$URL" | grep -Po "(?<=<p>openssl-$COMMAND - ).*(?=</p>)")
    echo "* [$COMMAND]($URL) : $DESCR"
done
