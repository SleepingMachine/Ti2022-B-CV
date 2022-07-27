//
// Created by eaibot71 on 22-7-27.
//

#include "../../include/switch/switch-control.hpp"

SwitchControl::SwitchControl() {}

void SwitchControl::SwitchStream(cv::Mat *import_src_0, cv::Mat *import_src_1) {
    ReadConfig();
    IdentifyTools::CreatTrackbars(
            &ShapeIdentify::hmin_R_, &ShapeIdentify::hmax_R_, &ShapeIdentify::smin_R_,
            &ShapeIdentify::smax_R_, &ShapeIdentify::vmin_R_, &ShapeIdentify::vmax_R_,

            &ShapeIdentify::hmin_B_, &ShapeIdentify::hmax_B_, &ShapeIdentify::smin_B_,
            &ShapeIdentify::smax_B_, &ShapeIdentify::vmin_B_, &ShapeIdentify::vmax_B_,

            &ShapeIdentify::open_, &ShapeIdentify::close_, &ShapeIdentify::erode_, &ShapeIdentify::dilate_

    );
    while(true){
        ShapeIdentify::ShapeIdentifyStream(import_src_0);
    }
}


int SwitchControl::ReadConfig() {
    rr::RrConfig config;
    bool ret = config.ReadConfig("../asset/config.ini");
    if (ret == false) {
        printf("ReadConfig is Error,Cfg=%s", "config.ini");
        return 1;
    }

    std::string UserName            = config.ReadString("CONFIG", "UserName", "");

    std::string _save_video         = config.ReadString("RMCONFIG", "EnableSaveVideo", "false");
    std::string _operating_mode     = config.ReadString("RMCONFIG", "OperatingMode", "EXCHANGE_MODE");
    std::string _ore_drop_detection = config.ReadString("RMCONFIG", "OreDropDetection", "false");
    int _realsense_camera_exposure  = config.ReadInt   ("RMCONFIG", "RealsenseCameraExposure", -1);

    std::cout << "User::" << UserName << std::endl;
    /*
    if (_operating_mode == "SEARCH_MODE"){
        SwitchControl::functionConfig_._operating_mode = OperatingMode::SEARCH_MODE;
    }
    else if (_operating_mode == "EXCHANGE_MODE"){
        SwitchControl::functionConfig_._operating_mode = OperatingMode::EXCHANGE_MODE;
    }
    if (_save_video == "true"){
        SwitchControl::functionConfig_._enable_save_video = true;
    }
    else if (_save_video == "false"){
        SwitchControl::functionConfig_._enable_save_video = false;
    }
    if (_ore_drop_detection == "true"){
        SwitchControl::functionConfig_._enable_ore_drop_detection = true;
    }
    else if (_ore_drop_detection == "false"){
        SwitchControl::functionConfig_._enable_ore_drop_detection = false;
    }

    CameraStream::cameraPara_.realsense_camera_exposure = _realsense_camera_exposure;
    */
}

namespace rr
{
    bool RrConfig::IsSpace(char c)
    {
        if (' ' == c || '\t' == c)
            return true;
        return false;
    }

    bool RrConfig::IsCommentChar(char c)
    {
        switch (c) {
            case '#':
                return true;
            default:
                return false;
        }
    }

    void RrConfig::Trim(std::string & str)
    {
        if (str.empty())
        {
            return;
        }
        int i, start_pos, end_pos;
        for (i = 0; i < str.size(); ++i) {
            if (!IsSpace(str[i])) {
                break;
            }
        }
        if (i == str.size())
        {
            str = "";
            return;
        }
        start_pos = i;
        for (i = str.size() - 1; i >= 0; --i) {
            if (!IsSpace(str[i])) {
                break;
            }
        }
        end_pos = i;
        str = str.substr(start_pos, end_pos - start_pos + 1);
    }

    bool RrConfig::AnalyseLine(const std::string & line, std::string& section, std::string & key, std::string & value)
    {
        if (line.empty())
            return false;
        int start_pos = 0, end_pos = line.size() - 1, pos, s_startpos, s_endpos;
        if ((pos = line.find("#")) != -1)
        {
            if (0 == pos)
            {
                return false;
            }
            end_pos = pos - 1;
        }
        if (((s_startpos = line.find("[")) != -1) && ((s_endpos = line.find("]"))) != -1)
        {
            section = line.substr(s_startpos + 1, s_endpos - 1);
            return true;
        }
        std::string new_line = line.substr(start_pos, start_pos + 1 - end_pos);
        if ((pos = new_line.find('=')) == -1)
            return false;
        key = new_line.substr(0, pos);
        value = new_line.substr(pos + 1, end_pos + 1 - (pos + 1));
        Trim(key);
        if (key.empty()) {
            return false;
        }
        Trim(value);
        if ((pos = value.find("\r")) > 0)
        {
            value.replace(pos, 1, "");
        }
        if ((pos = value.find("\n")) > 0)
        {
            value.replace(pos, 1, "");
        }
        return true;
    }

    bool RrConfig::ReadConfig(const std::string & filename)
    {
        settings_.clear();
        std::ifstream infile(filename.c_str());//构造默认调用open,所以可以不调用open
        //std::ifstream infile;
        //infile.open(filename.c_str());
        //bool ret = infile.is_open()
        if (!infile) {
            return false;
        }
        std::string line, key, value, section;
        std::map<std::string, std::string> k_v;
        std::map<std::string, std::map<std::string, std::string> >::iterator it;
        while (getline(infile, line))
        {
            if (AnalyseLine(line, section, key, value))
            {
                it = settings_.find(section);
                if (it != settings_.end())
                {
                    k_v[key] = value;
                    it->second = k_v;
                }
                else
                {
                    k_v.clear();
                    settings_.insert(std::make_pair(section, k_v));
                }
            }
            key.clear();
            value.clear();
        }
        infile.close();
        return true;
    }

    std::string RrConfig::ReadString(const char* section, const char* item, const char* default_value)
    {
        std::string tmp_s(section);
        std::string tmp_i(item);
        std::string def(default_value);
        std::map<std::string, std::string> k_v;
        std::map<std::string, std::string>::iterator it_item;
        std::map<std::string, std::map<std::string, std::string> >::iterator it;
        it = settings_.find(tmp_s);
        if (it == settings_.end())
        {
            //printf("111");
            return def;
        }
        k_v = it->second;
        it_item = k_v.find(tmp_i);
        if (it_item == k_v.end())
        {
            //printf("222");
            return def;
        }
        return it_item->second;
    }

    int RrConfig::ReadInt(const char* section, const char* item, const int& default_value)
    {
        std::string tmp_s(section);
        std::string tmp_i(item);
        std::map<std::string, std::string> k_v;
        std::map<std::string, std::string>::iterator it_item;
        std::map<std::string, std::map<std::string, std::string> >::iterator it;
        it = settings_.find(tmp_s);
        if (it == settings_.end())
        {
            return default_value;
        }
        k_v = it->second;
        it_item = k_v.find(tmp_i);
        if (it_item == k_v.end())
        {
            return default_value;
        }
        return atoi(it_item->second.c_str());
    }

    float RrConfig::ReadFloat(const char* section, const char* item, const float& default_value)
    {
        std::string tmp_s(section);
        std::string tmp_i(item);
        std::map<std::string, std::string> k_v;
        std::map<std::string, std::string>::iterator it_item;
        std::map<std::string, std::map<std::string, std::string> >::iterator it;
        it = settings_.find(tmp_s);
        if (it == settings_.end())
        {
            return default_value;
        }
        k_v = it->second;
        it_item = k_v.find(tmp_i);
        if (it_item == k_v.end())
        {
            return default_value;
        }
        return atof(it_item->second.c_str());
    }
}
