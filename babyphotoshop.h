#ifndef BABYPHOTOSHOP_H
#define BABYPHOTOSHOP_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class PhotoWizard;
}
QT_END_NAMESPACE

class BabyPhotoshop : public QMainWindow
{
    Q_OBJECT

public:
    BabyPhotoshop(QWidget *parent = nullptr);
    ~BabyPhotoshop();

private slots:
    void on_load_clicked();

    void on_invert_clicked();

    void on_b_w_clicked();


    void on_gray_clicked();

    void on_light_clicked();

    void on_dark_clicked();

    void on_frame_clicked();

    void on_blur_clicked();

    void on_ir_clicked();

    void on_dark_red_clicked();

    void on_flip_v_clicked();

    void on_flip_h_clicked();

    void on_save_clicked();

    void on_rotate_clicked();

    void on_sunlight_clicked();

    void on_tv_clicked();

    void on_purple_clicked();

    void on_slytherin_clicked();

    void on_previous_clicked();

    void on_clear_clicked();

    void on_resize_clicked();

    void on_crop_clicked();

    void on_detect_clicked();

    void on_skew_clicked();

    void on_oil_clicked();

    void on_merge_clicked();

private:
    Ui::PhotoWizard *ui;
};
#endif // BABYPHOTOSHOP_H
