#include "Musics.h"



Musics::Musics()
{
	 SongMusic = NULL;
	 SongEngine = irrklang::createIrrKlangDevice();

	 SFX1 = NULL;
	 SFXEngine1 =irrklang::createIrrKlangDevice();

	 SFX2 = NULL;
	 SFXEngine2 = irrklang::createIrrKlangDevice();
	/* irrklang::createIrrKlangDevice();
	 = irrklang::createIrrKlangDevice();
	 >setDefault3DSoundMinDistance(1.f);
	 >setDefault3DSoundMaxDistance(10.f);*/
}
Musics::~Musics()
{
	SFXEngine1->drop();
	SongEngine->drop();
}
void Musics::playMusic(std::string music)
{
	SongMusic = SongEngine->play2D(music.c_str(), true, false, true);
}
void Musics::stopMusic(std::string music)
{
	SongMusic->stop();
}

void Musics::playSFX(std::string Music, bool startpaused, bool repeat,int whichEngine)
{
	if (whichEngine==1)
	SFX1= SFXEngine1->play2D(Music.c_str(), repeat, startpaused, false);
	else
	SFX2= SFXEngine2->play2D(Music.c_str(), repeat, startpaused, false);
}

irrklang::ISound* Musics::getSound( int whichEngine)
{
	if (whichEngine == 1)
		return SFX1;
	else
		return SFX2;
}
void Musics::setSound(irrklang::ISound* sound , int whichEngine)
{
	if (whichEngine == 1)
		this->SFX1 = sound;
	else
		this->SFX2 = sound;
}
void  Musics::setIsPaused(bool set)
{
	SFX1->setIsPaused(set);
	SFX2->setIsPaused(set);
}
//bool  Musics::getPaused()
//{
//	return SFX->getIsPaused();
//}


ISoundEngine*  Musics::getSFXEngine(int whichEngine)
{
	if (whichEngine == 1)
		return SFXEngine1;
	else
		return SFXEngine2;
}
//
//void Sound::playMusic(string Music)
//{
//	//Song->setVolume(0.5f);
//	Song = musicEngine->play2D(Music.c_str(), true, false, true);
//}
//
//void Sound::playSE(string Music, bool startpaused)
//{
//	SoundEffect = musicEngine->play2D(Music.c_str(), false, startpaused, false);
//}
//void Sound::play3dSound(string Music, irrklang::vec3df pos, irrklang::vec3df view, irrklang::vec3df targetpos)
//{
//	//SoundEffect3D->setSoundVolume(2.0f);
//	SoundEffect3D->play3D(Music.c_str(), targetpos);
//	SoundEffect3D->setListenerPosition(pos, view);
//}
//
//void Sound::stopMusic(string Music)
//{
//	Song->stop();
//}
//void Sound::setIsPaused(bool set)
//{
//	SoundEffect->setIsPaused(set);
//}
//
//void Sound::pause()
//{
//	Song->setIsPaused(true);
//}
//
//bool Sound::getPaused()
//{
//	return SoundEffect->getIsPaused();
//}
//void Sound::dropMusic()
//{
//	Song->drop();
//}
//irrklang::ISound* Sound::getSound()
//{
//	return SoundEffect;
//}
//void Sound::setSound(irrklang::ISound* sound)
//{
//	this->SoundEffect = sound;
//}
//
//
