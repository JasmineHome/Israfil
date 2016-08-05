#include "israfilplayer.h"

IsrafilPlayer::~IsrafilPlayer()
{}

IsrafilPlayer::IsrafilPlayer()
  : m_volume(50), m_progress(0)
{
  m_player   = new QMediaPlayer(this, QMediaPlayer::StreamPlayback);
  m_playlist = new QMediaPlaylist();

  m_player->setPlaylist(m_playlist);

  connect(m_player, &QMediaPlayer::durationChanged, this, &IsrafilPlayer::changeDuration);
  connect(m_player, &QMediaPlayer::positionChanged, this, &IsrafilPlayer::changeProgress);
}

void IsrafilPlayer::mediaPlay()
{
  m_player->play();
}

void IsrafilPlayer::mediaPause()
{
  m_player->pause();
}

void IsrafilPlayer::mediaStop()
{
  m_player->stop();
}

void IsrafilPlayer::mediaNext()
{
  m_playlist->next();
}

void IsrafilPlayer::mediaPrevious()
{
  m_playlist->previous();
}

void IsrafilPlayer::mediaJump(int index)
{
  m_playlist->setCurrentIndex(index);
  m_player->play();
}

void IsrafilPlayer::mediaRemove(int index)
{
  m_playlist->removeMedia(index);
}

int IsrafilPlayer::getVolume() const
{
  return m_volume;
}

int IsrafilPlayer::getProgress() const
{
  return m_player->position();
}

int IsrafilPlayer::getDuration() const
{
  return m_player->duration();
}

int IsrafilPlayer::getState() const
{
  auto mstate = m_player->state();

  if (mstate == QMediaPlayer::StoppedState) return 0;

  if (mstate == QMediaPlayer::PlayingState) return 1;

  if (mstate == QMediaPlayer::PausedState) return 2;
}

int IsrafilPlayer::getSec()
{
  if (m_player->position() / 1000 < 60) {
    m_sec = m_player->position() / 1000;
  }
  else {
    int counter = (m_player->position() / 1000) / 60;
    m_sec = m_player->position() / 1000;

    if (counter >= 1) {
      m_sec = m_sec - (counter * 60);
    }
  }
  return m_sec;
}

int IsrafilPlayer::getMin()
{
  m_min =  (m_player->position()) / 60000;
  return m_min;
}

void IsrafilPlayer::setVolume(int volume)
{
  m_volume = volume;
  m_player->setVolume(m_volume);
}

void IsrafilPlayer::setProgress(int progress)
{
  if (progress == m_player->position()) return;
  else m_player->setPosition(progress);
}

void IsrafilPlayer::setFileUrl(QString url)
{
  m_playlist->addMedia(QUrl(url));
  m_fileUrl = url;
}

void IsrafilPlayer::changeTitle(QString stitle)
{
  if (m_fileUrl.isNull()) m_title = "NO_SONG";
  else {
    /*m_fileUrl = m_player->currentMedia().canonicalUrl().toString();
       m_fileUrl = m_fileUrl.replace(0,7,"");
       TagLib::FileRef f(m_fileUrl.toUtf8());
       TagLib::String artist_string = f.tag()->artist();
       TagLib::String title_string = f.tag()->title();
       QString artist = QString::fromStdWString(artist_string.toWString());
       QString title = QString::fromStdWString(title_string.toWString());
       QString string = artist + " - " + title;*/
    m_title = stitle;

    // return  string;
  }
}

void IsrafilPlayer::changeProgress(int value)
{
  m_progress = value;
  emit progressChanged();
}

void IsrafilPlayer::changeDuration(int value)
{
  m_duration = value;
  emit durationChanged();
}

void IsrafilPlayer::changeFileUrl(QString url)
{
  m_fileUrl = url;
  emit fileUrlChanged();
}

void IsrafilPlayer::insertMedia(QString URL, int ind = -1)
{
  if (ind == -1) {
    m_playlist->addMedia(QUrl(URL));
  } else {
    m_playlist->insertMedia(ind, QUrl(URL));
  }
}

void IsrafilPlayer::deleteMedia(int ind)
{
    if (ind == -1)//delete all
        m_playlist->removeMedia(0, m_playlist->mediaCount());
    else {
        m_playlist->removeMedia(ind);
    }
}
