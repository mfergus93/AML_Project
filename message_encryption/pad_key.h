//pad_key.h, Matthew Ferguson, 11/10/2023
//Pad Key Manager singleton class impelementation

#ifndef PAD_KEY_H
#define PAD_KEY_H
#include <string>
#include <QString>

class PadKey
{
public:

    static PadKey& getInstance();
    //Get current padkey
    std::string getUsePadKey() const;//Pad Key used by OTP objects
    QString getDisplayPadKey() const;//Pad Key we display

    //Set a new padkey
    void setNewPadKey();//Regenerate Pad Key

private:

    PadKey();
    static PadKey instance;
    std::string pad_key;
    QString pad_display;

};
#endif // PAD_KEY_H
