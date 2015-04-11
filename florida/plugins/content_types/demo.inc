<?php
/**
 * @file
 * Defines the top related content list panels pane.
 */

$plugin = array(
  'title' => t('Demo Plugin'),
  'description' => t('An Easy Content Type Plugin.'),
  'category' => array(t('Super Sweet Content'), 0),
  'edit form' => 'florida_ct_demo_form',
  'render callback' => 'florida_ct_demo_render',
);

/**
 * Edit form.
 */
function florida_ct_demo_form($form, &$form_state) {
  return $form;
}

/**
 * Render callback.
 */
function florida_ct_demo_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = t('Demo content type plugin');
  $block->content = t('Hello World');
  return $block;
}
