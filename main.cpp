#include "mainwindow.h"

/*
#include <unistd.h> // for fork()
#include <sys/types.h> // for pid_t
#include <sys/wait.h> // for waitpid()
#include "pirexception.h"
#include <sstream>
#include <errno.h>
*/

#include <QtGui/QApplication>

/*
int loadRX51Module()
{
  // First, fork off a child process:
  pid_t pid = fork();

  if (pid == -1)
  {
    // The fork failed!  Tell our user about the error:
    std::stringstream ss;
    ss << "Failed to fork a child process.\n";
    ss << "Error returned was: " << strerror(errno) << "\n";
    PIRException e(ss.str());
    e.display();
    return -1;
  }
  else if (pid == 0)
  {
    // We're inside the child process, so exec a modprobe:
    execl("/sbin/modprobe", "/sbin/modprobe", "lirc_rx51", NULL);
    // The execl call should overwrite the child process.  So, if we still
    // exist at this point, an error has occurred:
    std::stringstream ss;
    ss << "Failed to successfully call execl().\n";
    ss << "Error returned was: " << strerror(errno) << "\n";
    PIRException e(ss.str());
    e.display();
    return -1;
  }

  // If we reach this point, we are inside the parent process.  So, we'll wait
  // for the child process to complete:
  int *stat_loc = NULL;
  if (waitpid(pid, stat_loc, 0) == -1)
  {
    // The call to modprobe failed.
    std::stringstream ss;
    ss << "Call to modprobe failed.\n";
    ss << "Error returned was: " << strerror(errno) << "\n";
    PIRException e(ss.str());
    e.display();
    return -1;
  }

  if (stat_loc)
  {
    if (WIFEXITED(*stat_loc) == 0)
    {
      // modprobe encountered an error of some sort.
      std::stringstream ss;
      ss << "'modprobe' was unable to load the lirc_rx51 module.\n";
      // Need better details about the error here!
      PIRException e(ss.str());
      e.display();
      return -1;
    }
  }

  // By this point, we should have successfully ensured the module is loaded.
  return 0;
}
*/

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  MainWindow mainWindow;
  mainWindow.setOrientation(MainWindow::ScreenOrientationLockLandscape);
  mainWindow.showExpanded();

/*
  // Make sure lirc_rx51 module is loaded:
  if (loadRX51Module() != 0)
  {
    // Couldn't load module, quit:
    app.quit();
  }
*/

  return app.exec();
}

