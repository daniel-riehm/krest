/* This file is part of SEAL-TK, and is distributed under the OSI-approved BSD
 * 3-Clause License. See top-level LICENSE file or
 * https://github.com/Kitware/seal-tk/blob/master/LICENSE for details. */

#ifndef sealtk_core_VideoSource_hpp
#define sealtk_core_VideoSource_hpp

#include <sealtk/core/Export.h>

#include <QImage>
#include <QObject>
#include <QSet>
#include <qtGlobal.h>

#include <vital/types/image_container.h>
#include <vital/types/timestamp.h>

namespace sealtk
{

namespace core
{

class VideoSourcePrivate;

class SEALTK_CORE_EXPORT VideoSource : public QObject
{
  Q_OBJECT

public:
  explicit VideoSource(QObject* parent = nullptr);
  ~VideoSource() override;

  virtual QSet<kwiver::vital::timestamp::time_t> times() const = 0;

signals:
  void kwiverImageDisplayed(
    kwiver::vital::image_container_sptr const& image) const;
  void noImageDisplayed() const;
  void videoInputChanged() const;

public slots:
  virtual void invalidate() const = 0;
  virtual void seek(kwiver::vital::timestamp::time_t time) = 0;

protected:
  QTE_DECLARE_PRIVATE(VideoSource)

private:
  QTE_DECLARE_PRIVATE_RPTR(VideoSource)
};

}

}

#endif
