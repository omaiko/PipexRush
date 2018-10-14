# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int	main(int argc, char **argv)
{
	int fd1 = open("file1", O_RDWR);
	int fd2 = open("file2", O_RDWR);

	dup2(fd1, 0);
	write(0, "JJJ\n", 4);
}