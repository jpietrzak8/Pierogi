#include "pirmodprobe.h"

#include <unistd.h> // for fork()
#include <sys/types.h> // for pid_t
#include <sys/wait.h> // for waitpid()
#include "pirexception.h"
#include <sstream>
#include <errno.h>
#include <sys/stat.h>

PIRModprobe::PIRModprobe()
  : successfullyLoadedModule(false)
{
}


PIRModprobe::~PIRModprobe()
{
  if (successfullyLoadedModule)
  {
    unloadRX51Module();
  }
}


int PIRModprobe::loadRX51Module()
{
  // First, has the module already been loaded?  If /dev/lirc0 exists, it
  // should already be there:
  struct stat statBuffer;
  if (stat("/dev/lirc0", &statBuffer) == 0)
  {
    // "/dev/lirc0" exists, so no need to do anything:
    successfullyLoadedModule = false;
    return 0;
  }

  // Do the hard work: start by forking off a child process:
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
    // We're inside the child process, so exec the load module script:
    execl(
      "/usr/bin/sudo",
      "/usr/bin/sudo",
      "/opt/pierogi/bin/loadRX51Module",
      NULL);

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
      ss << "Unable to load the lirc_rx51 module.\n";
      // Need better details about the error here!
      PIRException e(ss.str());
      e.display();
      return -1;
    }
  }

  // By this point, we should have successfully loaded module.
  successfullyLoadedModule = true;

  return 0;
}


int PIRModprobe::unloadRX51Module()
{
  // start by forking off a child process:
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
    // We're inside the child process, so exec the unload script:
    execl(
      "/usr/bin/sudo",
      "/usr/bin/sudo",
      "/opt/pierogi/bin/unloadRX51Module",
      NULL);

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
      ss << "Unable to unload the lirc_rx51 module.\n";
      // Need better details about the error here!
      PIRException e(ss.str());
      e.display();
      return -1;
    }
  }

  // If we reach this point, module has been unloaded successfully:
  successfullyLoadedModule = false;

  return 0;
}
