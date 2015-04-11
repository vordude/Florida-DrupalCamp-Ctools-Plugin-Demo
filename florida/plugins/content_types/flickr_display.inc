<?php

$plugin = array(
  'title' => t('Flickr Image Display'),
  'description' => t('Honestly, it is a stretch to show off relationships.)'),
  'category' => array(t('Super Sweet Content'), 0),
  'edit form' => 'florida_flickr_content_type_form',
  'render callback' => 'florida_flickr_content_type_render',
  'required context' => new ctools_context_required(t('Flickr Relationship From Node'), 'florida_flickr_context'),
);

/**
 * Edit form.
 */
function florida_flickr_content_type_form($form, &$form_state) {
  return $form;
}

/**
 * Render callback.
 */
function florida_flickr_content_type_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = t('Related Flickr Images');
  $block->content = theme_item_list(array(
    'items' => $context->data->flickr_images,
    'title' => '',
    'type' => 'ul',
    'attributes' => array(),
  ));
  return $block;
}
