# ./main.py -n_epochs 500 -batch_size 500 -alpha 0.05 -optimizer Adam -lr 0.003 -weight_decay 0 -step_size 5 -gamma 0.95 -early_stop 10 -save_path models/MF_100K.pth -D 20 -dataset ML100K

# ./main.py -n_epochs 500 -batch_size 5000 -alpha 0.05 -optimizer Adam -lr 0.003 -weight_decay 0 -step_size 5 -gamma 0.95 -early_stop 10 -save_path models/MF_1M.pth -D 20 -dataset ML1M

./main.py -n_epochs 500 -batch_size 5000 -alpha 0.05 -optimizer Adam -lr 0.01 -weight_decay 0 -step_size 1 -gamma 0.9 -early_stop 10 -save_path models/MF_1M.pth -D 20 -dataset ML1M