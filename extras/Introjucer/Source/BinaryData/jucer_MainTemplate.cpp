/*
  ==============================================================================

    This file was auto-generated by the Jucer!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

APPHEADERS


//==============================================================================
class APPCLASSNAME  : public JUCEApplication
{
public:
    //==============================================================================
    APPCLASSNAME()MEMBERINITIALISERS
    {
    }

    ~APPCLASSNAME()
    {
    }

    //==============================================================================
    void initialise (const String& commandLine)
    {
        // Do your application's initialisation code here..
        APPINITCODE
    }

    void shutdown()
    {
        // Do your application's shutdown code here..
        APPSHUTDOWNCODE
    }

    //==============================================================================
    void systemRequestedQuit()
    {
        quit();
    }

    //==============================================================================
    const String getApplicationName()
    {
        return "APPNAME";
    }

    const String getApplicationVersion()
    {
        return ProjectInfo::versionString;
    }

    bool moreThanOneInstanceAllowed()
    {
        return ALLOWMORETHANONEINSTANCE;
    }

    void anotherInstanceStarted (const String& commandLine)
    {
        ANOTHERINSTANCECODE
    }

private:
    PRIVATEMEMBERS
};

//==============================================================================
// This macro generates the main() routine that starts the app.
START_JUCE_APPLICATION(APPCLASSNAME)