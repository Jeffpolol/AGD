#include <irrKlang.h>
#include <vector>
using namespace irrklang;
using std::vector;


class Musics
{
public:
	Musics();
	~Musics();
	

	void playMusic(std::string music);
	void stopMusic(std::string music);

	void playSFX(std::string Music, bool startpaused,bool repeat,int whichEngine);
	
	irrklang::ISound* getSound(int whichEngine);
	void setSound(irrklang::ISound* sound, int whichEngine);

	void setIsPaused(bool set);
	//bool getPaused();

	ISoundEngine* getSFXEngine(int whichEngine);
private:
	ISound* SongMusic;
	ISoundEngine* SongEngine;

	ISound* SFX1;
	ISoundEngine* SFXEngine1;

	ISound* SFX2;
	ISoundEngine* SFXEngine2;

};