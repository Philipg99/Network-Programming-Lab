#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <unistd.h>
#include <stdio.h>
#include <string.h>

struct stud
{
	int roll;
	char name[11];
	char branch[4];
	
}temp,rdr;


int main()
{
	int fd;
	ssize_t nr;
	off_t ret;
	int count=0,c=1,i,ss;
	fd = open ("file", O_RDWR | O_CREAT | O_TRUNC, 0777 ); 
	

	printf("%d %s %s\n",rdr.roll,rdr.name,rdr.branch);
	printf("1.enter 2.search 3.exit\n");

	while (c!=3){
		scanf("%d",&c);

		if (c==1){
			ret = lseek (fd, (off_t) 0, SEEK_END);
			scanf("%d %s %s",&temp.roll,temp.name,temp.branch);
			write (fd, &temp, sizeof(temp));
			count++;
		}

		if (c==2){
			printf("search by roll no: ");
			scanf("%d",&ss);
			i=0;
			while(i<count){
				ret = lseek (fd, (off_t) i*(sizeof(rdr)), SEEK_SET);
				nr = read (fd, &rdr, sizeof(rdr));
				if (ss==rdr.roll) printf("%d %s %s\n",rdr.roll,rdr.name,rdr.branch);
				i++;
			}
		}

	}



	close (fd);
	return 0;
}