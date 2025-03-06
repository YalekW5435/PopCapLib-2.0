A much requested version of PopCap's old SexyAppBase framework, which instead of using outdated old framework code,
it instead wraps into a more modern approach, by wrapping already usable functions and variables into SFML parameters.
This was done because the older version used old legacy drawing methods based off of DX/D3D7-9, that were not open to the public,
and were deemed as incompatible starting on Windows 11/later versions of linux and macOS.
This will also make this library a lot more platform independent, therefore making it cross-platform with no problem, 
and will also port the library to modern gaming and operating systems.  
We have unfortunately decided to remove all naming spaces of Sexy, and replace it with PopLib,
because the names of Sexy have unfortunately originated from an obscure poster called "Sexy Action Cool".

This library is still under development, and features may be unstable for the time.  No release date has been scheduled, as it is in early phases of development.

The library is released under the MIT license, further restrictions could apply to those who want to use this in a commercial envrionment.

# WHAT YOU WILL NEED:
cmake for windows, linux or macos, etc.
MSVC (for windows), and match such according to OS build number (for example 24H2 being 10.0.26100), and C++ standards specified in the cmakelists.txt.
(In visual studio, you can install these via the installer app).

# WINDOWS/VISUAL STUDIO:
The cmake stuff will automatically fetch the necessary files from the SFML repositories. It is set in an \external\ folder. 
We have also decided not to use WIN32 functionality anymore, (even though there is explicit mention of it in the cmakelists.txt), and stick only to x64 builds as that is what modern 
OSes are calling for nowadays.  The Windows API has been proven a pain in the ass for win32 and x64 compatibility in modern versions of windows which is completely uneccessary for x64 builds.
The project will adjust for you on x64 through the respected main() instead.  
# Other Info:
You do not need to build your project as an executable is already provided for your pleasure.  Based off of environment, it will also detect which system you have.
If you want to change the name of the project, goto the main cmake listed at the root folder of this library.

There will also be a file dedicated to future features that will be added per community requests, please look at "roadmaps.txt" for more details.
!!! We are also looking for contributors who wish to add on to this project.  I will be approving these as we go along.  

Happy Gaming!

