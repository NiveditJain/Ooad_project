#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

using std::string;

static const int READEND = 0;
static const int WRITEEND = 1;

int sendEmail(const string& to, const string& subject, const string& body) {
  int p2cFd[2];

  int ret = pipe(p2cFd);
  if (ret) {
    return ret;
  }

  pid_t child_pid = fork();
  if (child_pid < 0) {
    close(p2cFd[READEND]);
    close(p2cFd[WRITEEND]);

    return child_pid;
  }
  else if (!child_pid) {
    dup2(p2cFd[READEND], READEND);
    close(p2cFd[READEND]);
    close(p2cFd[WRITEEND]);

    execlp("mail", "mail", "-s", subject.c_str(), to.c_str(), NULL);

    exit(EXIT_FAILURE);
  }

  close(p2cFd[READEND]);

  ret = write(p2cFd[WRITEEND], body.c_str(), body.size());
  if (ret < 0) {
    return ret;
  }

  close(p2cFd[WRITEEND]);

  if (waitpid(child_pid, &ret, 0) == -1) {
    return ret;
  }

  return 0;
}

int main() {
  return sendEmail("jain.22@iitj.ac.in", "Subject", "Body");
}