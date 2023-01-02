#include <dirent.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_all_files(char *dir_name) {
  printf("Listing all files in %s\n", dir_name);

  struct dirent *dir_entry;
  DIR *dir_reader = opendir(dir_name);
  if (!dir_reader) {
    fprintf(stderr, "Cannot open directory '%s': %s\n", dir_name,
            strerror(errno));
    exit(EXIT_FAILURE);
  }

  while ((dir_entry = readdir(dir_reader)) != NULL) {
    if (strcmp(dir_entry->d_name, ".") == 0 ||
        strcmp(dir_entry->d_name, "..") == 0) {
      continue;
    }

    const char *f_name = dir_entry->d_name;
    if (dir_entry->d_type == DT_DIR) {
      char path[PATH_MAX];
      int path_length = snprintf(path, PATH_MAX, "%s/%s", dir_name, f_name);
      if (path_length >= PATH_MAX) {
        fprintf(stderr, "Path length has got too long.\n");
        exit(EXIT_FAILURE);
      }

      printf("Directory: %s\n", path);

      print_all_files(path);
    } else if (dir_entry->d_type == DT_REG) {
      printf("File: %s\n", f_name);
    }
  }

  if (closedir(dir_reader)) {
    fprintf(stderr, "Could not close '%s': %s\n", dir_name, strerror(errno));
    exit(EXIT_FAILURE);
  }
}

int main() {
  print_all_files(".");
  return EXIT_SUCCESS;
}
