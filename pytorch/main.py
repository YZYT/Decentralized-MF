#!/usr/bin/env python
# coding: utf-8

import torch
import torch.nn as nn
from torch.utils.data import Dataset, DataLoader

# For data preprocess
import numpy as np
import csv
import os

# For plotting
import matplotlib.pyplot as plt
from matplotlib.pyplot import figure
from utils.mylib import *
from d2l import torch as d2l


init_Seed()
device = get_device()                 # get the current available device ('cpu' or 'cuda')
os.makedirs('models', exist_ok=True)  # The trained model will be saved to ./models/
config = readConfig()

if config['dataset'] == 'ML100K':
    data_train = '../data/ML100K/ML100K_copy1_train.txt'
    data_test = '../data/ML100K/ML100K_copy1_test.txt'
    n_users = 1000
    n_items = 2000
    n_factors = 20
elif config['dataset'] == 'ML1M':
    data_train = '../data/ML1M/ML1M_copy1_train.txt'
    data_test = '../data/ML1M/ML1M_copy1_test.txt'
    n_users = 6050
    n_items = 4050
    n_factors = 20

tr_set = prep_dataloader(data_train, 'train', config['batch_size'])
dv_set = prep_dataloader(data_test, 'dev', config['batch_size'])
# tt_set = prep_dataloader("data/ML100K/ML100K_copy1_test.txt", 'test', config['batch_size'], target_only=target_only)

model = MF(n_users, n_items, n_factors).to(device) 
model_loss, model_loss_record = train(tr_set, dv_set, model, device, config)
print(np.sqrt(model_loss))

del model
model = MF(n_users, n_items, n_factors).to(device)
ckpt = torch.load(config['save_path'], map_location='cpu')  # Load your best model
model.load_state_dict(ckpt)
# plot_pred(dv_set, model, device)  # Show prediction on the validation set
print(dev(dv_set, model, device))

