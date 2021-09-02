import argparse

parser = argparse.ArgumentParser()
parser.add_argument('-batch_size', type=int)


args = parser.parse_args()

print(args.batch_size)