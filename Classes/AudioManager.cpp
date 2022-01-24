#include "AudioManager.h"
#include "cocos2d.h"
#include "AudioEngine.h"


int AudioManager::backgroundMusic = -1;

float AudioManager::backgroundVolume = 1.0f;

float AudioManager::effectVolume = 1.0f;

void AudioManager::playBackgroundMusic()
{
	backgroundMusic = cocos2d::experimental::AudioEngine::play2d("musics/backgroundMusic.mp3", true, backgroundVolume);
}

void AudioManager::stopBackgroundMusic()
{
	cocos2d::experimental::AudioEngine::stop(backgroundMusic);
}

void AudioManager::setBackgroundVolume(float volume)
{
	backgroundVolume = volume;
	cocos2d::experimental::AudioEngine::setVolume(backgroundMusic, volume);
}

void AudioManager::playSelectPokemonSoundEffect()
{
	cocos2d::experimental::AudioEngine::play2d("musics/selectPokemonSoundEffect.mp3", false, effectVolume);
}

void AudioManager::playRemovePokemonSoundEffect()
{
	cocos2d::experimental::AudioEngine::play2d("musics/removePokemonSoundEffect.mp3", false, effectVolume);
}

void AudioManager::setEffectVolume(float volume)
{
	effectVolume = volume;
}