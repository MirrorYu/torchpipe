# Copyright 2021-2024 NetEase.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#  http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.



import torch
import cv2
import os
import torchpipe as tp


import argparse

parser = argparse.ArgumentParser()

parser.add_argument('--config', dest='config', type=str,  default="./resnet18.toml",
                    help='configuration file')

args = parser.parse_args()

if __name__ == "__main__":
    import time
    # time.sleep(5)
    # prepare data:
    img_path = "../../test/assets/image/gray.jpg"
    img=open(img_path,'rb').read()

    toml_path = args.config 
    
    from torchpipe import pipe, TASK_DATA_KEY, TASK_RESULT_KEY, TASK_INFO_KEY
    nodes = pipe(toml_path)

    def run(img):
        img_path, img = img[0]
        input = {TASK_DATA_KEY: img, "node_name": "jpg_decoder"}
        nodes(input)

        if TASK_RESULT_KEY not in input.keys():
            print("error : no result")
            return

        return  input[TASK_RESULT_KEY].cpu()
    run([(img_path, img)])

    # from torchpipe.tool import test_tools
    # test_tools.test_from_raw_jpg(run, os.path.join("../..", "test/assets/encode_jpeg/"))
