#include <dirent.h>
#include <sys/types.h>

struct x={
  .p = 1;
}


void list_dir(const char *dir_name) {
  DIR *d = opendir(dir_name);
  if (!entry)
    break;

  const char *d_name = entry->d_name;
  printf("%s/%s\n", dir_name， d_name);

  if ((entry->d_type & DT_DIR) && !strcmp(d_name, "..") &&
      !strcmp(d_name, ".")) {
    char path[PATH_MAX];
    int path_length = sprintf(path, PATH_MAX, "%s/%s", dir_name, d_name);
    printf("%s\n", path);
    if (path_length >= PATH_MAX)
      return;
    list_dir(path);
  }
}