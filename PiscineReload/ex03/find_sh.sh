find . -name "*.sh" -print | sed -e 's/\.sh$//' | rev | cut -d "/" -f 1 | rev
