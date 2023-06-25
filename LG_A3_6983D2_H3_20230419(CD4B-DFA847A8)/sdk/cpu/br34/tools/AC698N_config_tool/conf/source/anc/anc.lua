if enable_moudles["anc"] == false then
    return;
else

--[[===================================================================================
=============================== 配置子项8: ANC参数配置 ================================
====================================================================================--]]
local anc_config = {
    dac_gain = {},
    ref_mic_gain = {},
    err_mic_gain = {},
    reserverd_cfg = {},
    anc_gain = {},
    transparency_gain = {},

    output = {
        anc_config_item_table = {},
        anc_config_output_view_table = {},
        anc_config_htext_output_table = {},
    },
};

anc_config.reference_book_view = cfg:stButton("JL ANC调试手册.pdf",
    function()
        local ret = cfg:utilsShellOpenFile(anc_reference_book_path);
        if (ret == false) then
            if cfg.lang == "zh" then
		        cfg:msgBox("info", anc_reference_book_path .. "文件不存在");
            else
		        cfg:msgBox("info", anc_reference_book_path .. " file not exist.");
            end
        end
    end);

-- 8-1 dac增益
anc_config.dac_gain.cfg = cfg:i32("dac_gain:  ", 8);
anc_config.dac_gain.cfg:setOSize(1);
-- item_htext
--mic_analog_gain.comment_str = "设置范围：0 ~ 19, 默认值：8";
--mic_analog_gain.htext = item_output_htext(mic_analog_gain.cfg, "TCFG_AEC_MIC_ANALOG_GAIN", 3, nil, mic_analog_gain.comment_str, 1);
-- item_view
anc_config.dac_gain.hbox_view = cfg:hBox {
    cfg:stLabel(anc_config.dac_gain.cfg.name .. TAB_TABLE[1]),
    cfg:ispinView(anc_config.dac_gain.cfg, 0, 15, 1),
    cfg:stLabel("(DAC增益，设置范围: 0 ~ 15，步进：1，默认值：8)"),
    cfg:stSpacer(),
};


-- 8-2 ref_mic_gain
anc_config.ref_mic_gain.cfg = cfg:i32("ref_mic_gain:  ", 6);
anc_config.ref_mic_gain.cfg:setOSize(1);
-- item_htext
--mic_analog_gain.comment_str = "设置范围：0 ~ 19, 默认值：8";
--mic_analog_gain.htext = item_output_htext(mic_analog_gain.cfg, "TCFG_AEC_MIC_ANALOG_GAIN", 3, nil, mic_analog_gain.comment_str, 1);
-- item_view
anc_config.ref_mic_gain.hbox_view = cfg:hBox {
    cfg:stLabel(anc_config.ref_mic_gain.cfg.name .. TAB_TABLE[1]),
    cfg:ispinView(anc_config.ref_mic_gain.cfg, 0, 19, 1),
    cfg:stLabel("(参考mic增益，设置范围: 0 ~ 19，步进：1，默认值：6)"),
    cfg:stSpacer(),
};

-- 8-3 err_mic_gain
anc_config.err_mic_gain.cfg = cfg:i32("err_mic_gain:  ", 6);
anc_config.err_mic_gain.cfg:setOSize(1);
-- item_htext
--mic_analog_gain.comment_str = "设置范围：0 ~ 19, 默认值：8";
--mic_analog_gain.htext = item_output_htext(mic_analog_gain.cfg, "TCFG_AEC_MIC_ANALOG_GAIN", 3, nil, mic_analog_gain.comment_str, 1);
-- item_view
anc_config.err_mic_gain.hbox_view = cfg:hBox {
    cfg:stLabel(anc_config.err_mic_gain.cfg.name .. TAB_TABLE[1]),
    cfg:ispinView(anc_config.err_mic_gain.cfg, 0, 19, 1),
    cfg:stLabel("(误差mic增益，设置范围: 0 ~ 19，步进：1，默认值：6)"),
    cfg:stSpacer(),
};

-- 8-4 reserverd_cfg 
anc_config.reserverd_cfg.cfg = cfg:i32("reserverd_cfg:  ", 8);
anc_config.reserverd_cfg.cfg:setOSize(1);
-- item_htext
--mic_analog_gain.comment_str = "设置范围：0 ~ 19, 默认值：8";
--mic_analog_gain.htext = item_output_htext(mic_analog_gain.cfg, "TCFG_AEC_MIC_ANALOG_GAIN", 3, nil, mic_analog_gain.comment_str, 1);
-- item_view
anc_config.reserverd_cfg.hbox_view = cfg:hBox {
    cfg:stLabel(anc_config.reserverd_cfg.cfg.name .. TAB_TABLE[1]),
    cfg:ispinView(anc_config.reserverd_cfg.cfg, 0, 15, 1),
    cfg:stLabel("(保留参数，设置范围: 0 ~ 15，步进：2dB 默认值：8)"),
    cfg:stSpacer(),
};

-- 8-5 anc_gain
anc_config.anc_gain.cfg = cfg:i32("anc_gain:  ", -8096);
anc_config.anc_gain.cfg:setOSize(4);
-- item_htext
--mic_analog_gain.comment_str = "设置范围：0 ~ 19, 默认值：8";
--mic_analog_gain.htext = item_output_htext(mic_analog_gain.cfg, "TCFG_AEC_MIC_ANALOG_GAIN", 3, nil, mic_analog_gain.comment_str, 1);
-- item_view
anc_config.anc_gain.hbox_view = cfg:hBox {
    cfg:stLabel(anc_config.anc_gain.cfg.name .. TAB_TABLE[1]),
    cfg:ispinView(anc_config.anc_gain.cfg, -32768, 32767, 1),
    cfg:stLabel("(降噪模式增益，设置范围: -32768 ~ 32767，步进：1， 默认值：-8096)"),
    cfg:stSpacer(),
};

-- 8-6 transparency_gain
anc_config.transparency_gain.cfg = cfg:i32("transparency_gain:  ", 7096);
anc_config.transparency_gain.cfg:setOSize(4);
-- item_htext
--mic_analog_gain.comment_str = "设置范围：0 ~ 19, 默认值：8";
--mic_analog_gain.htext = item_output_htext(mic_analog_gain.cfg, "TCFG_AEC_MIC_ANALOG_GAIN", 3, nil, mic_analog_gain.comment_str, 1);
-- item_view
anc_config.transparency_gain.hbox_view = cfg:hBox {
    cfg:stLabel(anc_config.transparency_gain.cfg.name),
    cfg:ispinView(anc_config.transparency_gain.cfg, -32768, 32767, 1),
    cfg:stLabel("(通透模式增益，设置范围: -32768 ~ 32767，步进：2dB 默认值：7096)"),
    cfg:stSpacer(),
};

--========================= ANC 参数输出汇总  ============================

anc_config.output.anc_config_item_table = {
    anc_config.dac_gain.cfg,
    anc_config.ref_mic_gain.cfg,
    anc_config.err_mic_gain.cfg,
    anc_config.reserverd_cfg.cfg,
    anc_config.anc_gain.cfg,
    anc_config.transparency_gain.cfg,
};

anc_config.output.anc_config_output_view_table = {
    anc_config.reference_book_view,
    anc_config.dac_gain.hbox_view,
    anc_config.ref_mic_gain.hbox_view,
    anc_config.err_mic_gain.hbox_view,
    --anc_config.reserverd_cfg.hbox_view,
    anc_config.anc_gain.hbox_view,
    anc_config.transparency_gain.hbox_view,
};

-- A. 输出htext
anc_config.output.anc_config_htext_output_table = {
};

-- B. 输出ctext：无

-- C. 输出bin
anc_config.output.anc_config_output_bin = cfg:group("anc_config",
	BIN_ONLY_CFG["HW_CFG"].anc_config.id,
	1,
    anc_config.output.anc_config_item_table
);

-- D. 显示
anc_config.output.anc_config_group_view = cfg:stGroup("ANC 参数配置",
    cfg:vBox (
        anc_config.output.anc_config_output_view_table
    )
);

-- E. 默认值, 见汇总

-- F. bindGroup
cfg:bindStGroup(anc_config.output.anc_config_group_view, anc_config.output.anc_config_output_bin);

--[[===================================================================================
==================================== 模块返回汇总 =====================================
====================================================================================--]]
-- A. 输出htext
--[[
-- AEC
insert_list_to_list(anc_output_htext_tabs, aec_output_htext_table);
--]]
-- B. 输出ctext：无
-- C. 输出bin：无
insert_item_to_list(anc_output_bin_tabs, anc_config.output.anc_config_output_bin);

-- E. 默认值
local anc_cfg_default_table = {};

--ans config
insert_list_to_list(anc_cfg_default_table, anc_config.output.anc_config_item_table);

local anc_default_button_view = cfg:stButton(" ANC配置恢复默认值 ", reset_to_default(anc_cfg_default_table));

-- D. 显示
local anc_output_group_view_table = {};


insert_item_to_list(anc_output_group_view_table, anc_config.output.anc_config_group_view);

if open_by_program == "create" then
end

anc_output_vbox_view = cfg:vBox {
    cfg:stHScroll(cfg:vBox(anc_output_group_view_table)),
    anc_default_button_view,
};

-- F. bindGroup：item单独处理

end

