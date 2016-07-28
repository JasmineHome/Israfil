#ifndef ISRAFILPLAYER_H
#define ISRAFILPLAYER_H
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMediaMetaData>
#include <QString>

// #include <taglib/fileref.h>
// #include <taglib/tstring.h>
class IsrafilPlayer : public QObject {
  Q_OBJECT
  Q_PROPERTY(int volume READ getVolume WRITE setVolume NOTIFY volumeChanged)
  Q_PROPERTY(int progress READ getProgress WRITE setProgress NOTIFY progressChanged)
  Q_PROPERTY(int duration READ getDuration NOTIFY durationChanged)
  Q_PROPERTY(QString fileUrl WRITE setFileUrl NOTIFY fileUrlChanged)
  Q_PROPERTY(int second READ getSec NOTIFY progressChanged)
  Q_PROPERTY(int minute READ getMin NOTIFY progressChanged)

public:

  ~IsrafilPlayer();
  IsrafilPlayer();
  int  getVolume() const;
  int  getProgress() const;
  int  getDuration() const;

  // QString getTitle();
  int  getMin();
  int  getSec();

  void setVolume(int volume);
  void setProgress(int progress);
  void setFileUrl(QString url);
  void setTitle(QString stitle);

private:

  QMediaPlayer   *m_player;
  QMediaPlaylist *m_playlist;

  int m_volume;
  int m_progress;
  int m_duration;
  QString m_fileUrl;
  int     m_min;
  int     m_sec;
  QString m_title;

public slots:

  void mediaPlay();
  void mediaPause();
  void mediaStop();
  void mediaNext();
  void mediaPrevious();
  void mediaJump(int);
  void mediaRemove(int);
  void changeProgress(int);
  void changeDuration(int);
  void changeFileUrl(QString);

signals:

  int volumeChanged();
  int progressChanged();
  int durationChanged();
  int fileUrlChanged();
};


#endif // ISRAFILPLAYER_H
