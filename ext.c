#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

static void
display_ext(const char *file)
{
	const char *last = strrchr(file, '.');

	printf("%s\n", last ? ++last : "");
}

static void
read_piped(FILE *file)
{
	char line[PATH_MAX];

	while (fgets(line, sizeof line, file)) {
		line[strcspn(line, "\r\n")] = '\0';
		display_ext(line);
	}
}

int
main(int argc, char **argv)
{
	if (!isatty(fileno(stdin)))
		read_piped(stdin);
	else if (argc > 1)
		while (*++argv)
			display_ext(*argv);
	else {
		fprintf(stderr,
			"usage:\n\t%s ...\n"
			"\nprovide a nonzero number of filenames\n"
			, argv[0]);
		return EXIT_FAILURE;
	}
}
